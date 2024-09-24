#include "PmergeMe.hpp"

#include <cstdlib>
#include <iostream>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    (void)rhs;
    return *this;
}

// the list
PmergeMe::PmergeMeList::PmergeMeList(void) {}

PmergeMe::PmergeMeList::PmergeMeList(const PmergeMeList &src) { (void)src; }

PmergeMe::PmergeMeList::~PmergeMeList(void) {}

PmergeMe::PmergeMeList &
PmergeMe::PmergeMeList::operator=(const PmergeMeList &rhs)
{
    if (this == &rhs)
        return *this;

    this->shuffled = rhs.shuffled;
    this->pairs = rhs.pairs;
    this->mainChain = rhs.mainChain;
    this->pend = rhs.pend;
    this->jacobsthalNumbers = rhs.jacobsthalNumbers;
    this->positions = rhs.positions;
    return *this;
}

unsigned PmergeMe::PmergeMeList::binarySearch(const std::list<int> &list,
                                              ssize_t begin, ssize_t end,
                                              int search)
{
    std::list<int>::const_iterator itMiddle;
    ssize_t middle = 0;
    while (begin <= end)
    {
        itMiddle = list.begin();
        middle = begin + ((end - begin) / 2);
        std::advance(itMiddle, middle);
        if (search == *itMiddle)
            break;
        if (search < *itMiddle)
            end = middle - 1;
        else
            begin = middle + 1;
    }
    if (search > *itMiddle)
        return ++middle;
    return middle;
}

void PmergeMe::PmergeMeList::sort(const char *const *argv)
{
    createShuffledList(argv);
    createPairsList();
    sortValuesWithinPairs();
    sortPairs();
    createMainAndPendList();
    generatPositions();
    insertPendIntoMainChain();
}

const std::list<int> &PmergeMe::PmergeMeList::getMainChain() const
{
    return this->mainChain;
}

void PmergeMe::PmergeMeList::createMainAndPendList()
{
    unsigned until = this->pairs.size();
    std::list<std::pair<int, int> >::iterator itPair = this->pairs.begin();
    for (unsigned countPairs = 0; countPairs < until; ++countPairs)
    {
        itPair = this->pairs.begin();
        std::advance(itPair, countPairs);
        mainChain.push_back(itPair->first);
        pend.push_back(itPair->second);
    }
    mainChain.push_front(pend.front());
}

void PmergeMe::PmergeMeList::createShuffledList(const char *const *argv)
{
    for (unsigned countArgs = 1; argv[countArgs]; countArgs++)
    {
        int intTempNumber = std::strtol(argv[countArgs], 0, 10);
        this->shuffled.push_back(intTempNumber);
    }
}

void PmergeMe::PmergeMeList::insertPendIntoMainChain()
{
    std::list<int>::iterator itCountJacobNumber;
    std::list<int>::iterator minorNumber;
    std::list<int>::iterator mainChainPosition;
    unsigned position;
    unsigned count = 0;
    unsigned endSearch = 0;

    for (itCountJacobNumber = positions.begin();
         itCountJacobNumber != positions.end(); ++itCountJacobNumber)
    {
        if (*itCountJacobNumber > (int)pend.size())
            continue;
        minorNumber = pend.begin();
        std::advance(minorNumber, *itCountJacobNumber - 1);
        endSearch = *itCountJacobNumber + count;
        position = binarySearch(mainChain, 0, endSearch, *minorNumber);
        mainChainPosition = mainChain.begin();
        std::advance(mainChainPosition, position);
        mainChain.insert(mainChainPosition, *minorNumber);
        count++;
    }
    if (shuffled.size() % 2)
    {
        int struggler = shuffled.back();
        position = binarySearch(mainChain, 0, mainChain.size() - 1, struggler);
        mainChainPosition = mainChain.begin();
        std::advance(mainChainPosition, position);
        mainChain.insert(mainChainPosition, struggler);
    }
}

void PmergeMe::PmergeMeList::createPairsList()
{
    for (unsigned countPairs = 0; countPairs < this->shuffled.size() - 1;
         countPairs += 2)
    {
        std::pair<int, int> tempPair;
        std::list<int>::iterator itFirst = this->shuffled.begin();
        std::list<int>::iterator itSecond = itFirst;
        std::advance(itFirst, countPairs);
        std::advance(itSecond, countPairs + 1);
        tempPair.first = *itFirst;
        tempPair.second = *itSecond;
        pairs.push_back(tempPair);
    }
}

void PmergeMe::PmergeMeList::sortValuesWithinPairs()
{
    unsigned until = this->pairs.size();
    std::list<std::pair<int, int> >::iterator itThePair;
    for (unsigned countPairs = 0; countPairs < until; ++countPairs)
    {
        itThePair = this->pairs.begin();
        std::advance(itThePair, countPairs);
        if (itThePair->second > itThePair->first)
        {
            itThePair->second ^= itThePair->first;
            itThePair->first ^= itThePair->second;
            itThePair->second ^= itThePair->first;
        }
    }
}

void PmergeMe::PmergeMeList::sortPairs()
{
    mergeSort(this->pairs, 0, this->pairs.size() - 1);
}

void PmergeMe::PmergeMeList::mergeSort(std::list<std::pair<int, int> > &pairList,
                                       unsigned begin, unsigned end)
{
    if (begin >= end)
        return;
    unsigned middle = begin + (end - begin) / 2;
    this->mergeSort(pairList, begin, middle);
    this->mergeSort(pairList, middle + 1, end);
    this->merge(pairList, begin, middle, end);
}

void PmergeMe::PmergeMeList::merge(std::list<std::pair<int, int> > &pairList,
                                   unsigned begin, unsigned middle,
                                   unsigned end)
{
    unsigned leftListIndex = 0;
    unsigned rightListIndex = 0;
    unsigned pairListIndex = begin;

    std::list<std::pair<int, int> >::iterator from = pairList.begin();
    std::list<std::pair<int, int> >::iterator until = from;
    std::advance(from, begin);
    std::advance(until, middle + 1);
    std::list<std::pair<int, int> > leftList(from, until);

    from = pairList.begin();
    until = from;
    std::advance(from, middle + 1);
    std::advance(until, end + 1);
    std::list<std::pair<int, int> > rightList(from, until);

    std::list<std::pair<int, int> >::iterator itPairInLeftList =
        leftList.begin();
    std::list<std::pair<int, int> >::iterator itPairInRightList =
        rightList.begin();
    std::list<std::pair<int, int> >::iterator itPairList = pairList.begin();

    while (leftListIndex < leftList.size() && rightListIndex < rightList.size())
    {
        itPairInLeftList = leftList.begin();
        itPairInRightList = rightList.begin();
        itPairList = pairList.begin();
        std::advance(itPairInLeftList, leftListIndex);
        std::advance(itPairInRightList, rightListIndex);
        std::advance(itPairList, pairListIndex);

        if (itPairInLeftList->first <= itPairInRightList->first)
        {
            itPairList->first = itPairInLeftList->first;
            itPairList->second = itPairInLeftList->second;
            leftListIndex++;
        }
        else
        {
            itPairList->first = itPairInRightList->first;
            itPairList->second = itPairInRightList->second;
            rightListIndex++;
        }
        pairListIndex++;
    }
    while (leftListIndex < leftList.size())
    {
        itPairInLeftList = leftList.begin();
        itPairList = pairList.begin();
        std::advance(itPairList, pairListIndex);
        std::advance(itPairInLeftList, leftListIndex);
        itPairList->first = itPairInLeftList->first;
        itPairList->second = itPairInLeftList->second;
        leftListIndex++;
        pairListIndex++;
    }
    while (rightListIndex < rightList.size())
    {
        itPairList = pairList.begin();
        itPairInRightList = rightList.begin();
        std::advance(itPairList, pairListIndex);
        std::advance(itPairInRightList, rightListIndex);
        itPairList->first = itPairInRightList->first;
        itPairList->second = itPairInRightList->second;
        rightListIndex++;
        pairListIndex++;
    }
}

int PmergeMe::PmergeMeList::jacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::PmergeMeList::generatPositions()
{
    size_t val;
    size_t pos;
    size_t lastPos;
    size_t i;

    if (this->pend.empty())
        return;
    this->generateJacobInsertionSequence();
    lastPos = 1;
    val = 1;
    i = 0;
    std::list<int>::iterator itJacobNumber;
    while (i < this->jacobsthalNumbers.size())
    {
        itJacobNumber = jacobsthalNumbers.begin();
        std::advance(itJacobNumber, i);
        val = *itJacobNumber;

        this->positions.push_back(val);

        pos = val - 1;
        while (pos > lastPos)
        {
            this->positions.push_back(pos);
            pos--;
        }
        lastPos = val;
        i++;
    }
    while (val++ < this->pend.size())
        this->positions.push_back(val);
}

void PmergeMe::PmergeMeList::generateJacobInsertionSequence()
{
    size_t size;
    size_t jcobstalIndex;
    int index;

    size = this->pend.size();
    index = 3;

    while ((jcobstalIndex = this->jacobsthal(index)) < size - 1)
    {
        this->jacobsthalNumbers.push_back(jcobstalIndex);
        index++;
    }
}

// ========================================================================

// the vector
PmergeMe::PmergeMeVector::PmergeMeVector(void) {}

PmergeMe::PmergeMeVector::PmergeMeVector(const PmergeMeVector &src)
{
    (void)src;
}

PmergeMe::PmergeMeVector::~PmergeMeVector(void) {}

PmergeMe::PmergeMeVector &
PmergeMe::PmergeMeVector::operator=(const PmergeMeVector &rhs)
{
    if (this == &rhs)
        return *this;

    this->shuffled = rhs.shuffled;
    this->pairs = rhs.pairs;
    this->mainChain = rhs.mainChain;
    this->pend = rhs.pend;
    this->jacobsthalNumbers = rhs.jacobsthalNumbers;
    this->positions = rhs.positions;
    return *this;
}

unsigned PmergeMe::PmergeMeVector::binarySearch(const std::vector<int> &list,
                                                ssize_t begin, ssize_t end,
                                                int search)
{
    std::vector<int>::const_iterator itMiddle;
    ssize_t middle = 0;
    while (begin <= end)
    {
        itMiddle = list.begin();
        middle = begin + ((end - begin) / 2);
        std::advance(itMiddle, middle);
        if (search == *itMiddle)
            break;
        if (search < *itMiddle)
            end = middle - 1;
        else
            begin = middle + 1;
    }
    if (search > *itMiddle)
        return ++middle;
    return middle;
}

void PmergeMe::PmergeMeVector::sort(const char *const *argv)
{
    createShuffledList(argv);
    createPairsList();
    sortValuesWithinPairs();
    sortPairs();
    createMainAndPendList();
    generatPositions();
    insertPendIntoMainChain();
}

void PmergeMe::PmergeMeVector::createMainAndPendList()
{
    unsigned until = this->pairs.size();
    std::list<std::pair<int, int> >::iterator itPair = this->pairs.begin();
    for (unsigned countPairs = 0; countPairs < until; ++countPairs)
    {
        itPair = this->pairs.begin();
        std::advance(itPair, countPairs);
        mainChain.push_back(itPair->first);
        pend.push_back(itPair->second);
    }
    mainChain.insert(mainChain.begin(), pend.front());
}

void PmergeMe::PmergeMeVector::createShuffledList(const char *const *argv)
{
    for (unsigned countArgs = 1; argv[countArgs]; countArgs++)
    {
        int intTempNumber = std::strtol(argv[countArgs], 0, 10);
        this->shuffled.push_back(intTempNumber);
    }
}

void PmergeMe::PmergeMeVector::insertPendIntoMainChain()
{
    std::vector<int>::iterator itCountJacobNumber;
    std::vector<int>::iterator minorNumber;
    std::vector<int>::iterator mainChainPosition;
    unsigned position;
    unsigned count = 0;
    unsigned endSearch = 0;

    for (itCountJacobNumber = positions.begin();
         itCountJacobNumber != positions.end(); ++itCountJacobNumber)
    {
        if (*itCountJacobNumber > (int)pend.size())
            continue;
        minorNumber = pend.begin();
        std::advance(minorNumber, *itCountJacobNumber - 1);
        endSearch = *itCountJacobNumber + count;
        position = binarySearch(mainChain, 0, endSearch, *minorNumber);
        mainChainPosition = mainChain.begin();
        std::advance(mainChainPosition, position);
        mainChain.insert(mainChainPosition, *minorNumber);
        count++;
    }
    if (shuffled.size() % 2)
    {
        int struggler = shuffled.back();
        position = binarySearch(mainChain, 0, mainChain.size() - 1, struggler);
        mainChainPosition = mainChain.begin();
        std::advance(mainChainPosition, position);
        mainChain.insert(mainChainPosition, struggler);
    }
}

void PmergeMe::PmergeMeVector::createPairsList()
{
    for (unsigned countPairs = 0; countPairs < this->shuffled.size() - 1;
         countPairs += 2)
    {
        std::pair<int, int> tempPair;
        std::vector<int>::iterator itFirst = this->shuffled.begin();
        std::vector<int>::iterator itSecond = itFirst;
        std::advance(itFirst, countPairs);
        std::advance(itSecond, countPairs + 1);
        tempPair.first = *itFirst;
        tempPair.second = *itSecond;
        pairs.push_back(tempPair);
    }
}

void PmergeMe::PmergeMeVector::sortValuesWithinPairs()
{
    unsigned until = this->pairs.size();
    std::list<std::pair<int, int> >::iterator itThePair;
    for (unsigned countPairs = 0; countPairs < until; ++countPairs)
    {
        itThePair = this->pairs.begin();
        std::advance(itThePair, countPairs);
        if (itThePair->second > itThePair->first)
        {
            itThePair->second ^= itThePair->first;
            itThePair->first ^= itThePair->second;
            itThePair->second ^= itThePair->first;
        }
    }
}

void PmergeMe::PmergeMeVector::sortPairs()
{
    mergeSort(this->pairs, 0, this->pairs.size() - 1);
}

void PmergeMe::PmergeMeVector::mergeSort(
    std::list<std::pair<int, int> > &pairList, unsigned begin, unsigned end)
{
    if (begin >= end)
        return;
    unsigned middle = begin + (end - begin) / 2;
    this->mergeSort(pairList, begin, middle);
    this->mergeSort(pairList, middle + 1, end);
    this->merge(pairList, begin, middle, end);
}

void PmergeMe::PmergeMeVector::merge(std::list<std::pair<int, int> > &pairList,
                                     unsigned begin, unsigned middle,
                                     unsigned end)
{
    unsigned leftListIndex = 0;
    unsigned rightListIndex = 0;
    unsigned pairListIndex = begin;

    std::list<std::pair<int, int> >::iterator from = pairList.begin();
    std::list<std::pair<int, int> >::iterator until = from;
    std::advance(from, begin);
    std::advance(until, middle + 1);
    std::list<std::pair<int, int> > leftList(from, until);

    from = pairList.begin();
    until = from;
    std::advance(from, middle + 1);
    std::advance(until, end + 1);
    std::list<std::pair<int, int> > rightList(from, until);

    std::list<std::pair<int, int> >::iterator itPairInLeftList =
        leftList.begin();
    std::list<std::pair<int, int> >::iterator itPairInRightList =
        rightList.begin();
    std::list<std::pair<int, int> >::iterator itPairList = pairList.begin();

    while (leftListIndex < leftList.size() && rightListIndex < rightList.size())
    {
        itPairInLeftList = leftList.begin();
        itPairInRightList = rightList.begin();
        itPairList = pairList.begin();
        std::advance(itPairInLeftList, leftListIndex);
        std::advance(itPairInRightList, rightListIndex);
        std::advance(itPairList, pairListIndex);

        if (itPairInLeftList->first <= itPairInRightList->first)
        {
            itPairList->first = itPairInLeftList->first;
            itPairList->second = itPairInLeftList->second;
            leftListIndex++;
        }
        else
        {
            itPairList->first = itPairInRightList->first;
            itPairList->second = itPairInRightList->second;
            rightListIndex++;
        }
        pairListIndex++;
    }
    while (leftListIndex < leftList.size())
    {
        itPairInLeftList = leftList.begin();
        itPairList = pairList.begin();
        std::advance(itPairList, pairListIndex);
        std::advance(itPairInLeftList, leftListIndex);
        itPairList->first = itPairInLeftList->first;
        itPairList->second = itPairInLeftList->second;
        leftListIndex++;
        pairListIndex++;
    }
    while (rightListIndex < rightList.size())
    {
        itPairList = pairList.begin();
        itPairInRightList = rightList.begin();
        std::advance(itPairList, pairListIndex);
        std::advance(itPairInRightList, rightListIndex);
        itPairList->first = itPairInRightList->first;
        itPairList->second = itPairInRightList->second;
        rightListIndex++;
        pairListIndex++;
    }
}

int PmergeMe::PmergeMeVector::jacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::PmergeMeVector::generatPositions()
{
    size_t val;
    size_t pos;
    size_t lastPos;
    size_t i;

    if (this->pend.empty())
        return;
    this->generateJacobInsertionSequence();
    lastPos = 1;
    val = 1;
    i = 0;
    std::vector<int>::iterator itJacobNumber;
    while (i < this->jacobsthalNumbers.size())
    {
        itJacobNumber = jacobsthalNumbers.begin();
        std::advance(itJacobNumber, i);
        val = *itJacobNumber;

        this->positions.push_back(val);

        pos = val - 1;
        while (pos > lastPos)
        {
            this->positions.push_back(pos);
            pos--;
        }
        lastPos = val;
        i++;
    }
    while (val++ < this->pend.size())
        this->positions.push_back(val);
}

void PmergeMe::PmergeMeVector::generateJacobInsertionSequence()
{
    size_t size;
    size_t jcobstalIndex;
    int index;

    size = this->pend.size();
    index = 3;

    while ((jcobstalIndex = this->jacobsthal(index)) < size - 1)
    {
        this->jacobsthalNumbers.push_back(jcobstalIndex);
        index++;
    }
}
