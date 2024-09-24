#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <cstdlib>
#include <list>
#include <vector>

class PmergeMe
{
  public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &src);
    ~PmergeMe(void);
    PmergeMe &operator=(const PmergeMe &rhs);

    class PmergeMeList
    {
      public:
        PmergeMeList(void);
        PmergeMeList(const PmergeMeList &src);
        ~PmergeMeList(void);

        void sort(const char *const *argv);
        const std::list<int> &getMainChain() const;

        PmergeMeList &operator=(const PmergeMeList &rhs);

      private:
        unsigned binarySearch(const std::list<int> &list, ssize_t begin,
                              ssize_t end, int search);
        void createMainAndPendList();
        void createPairsList();
        void createShuffledList(const char *const *argv);
        void generatPositions();
        void generateJacobInsertionSequence();
        void insertPendIntoMainChain();
        int jacobsthal(int n);
        void mergeSort(std::list<std::pair<int, int> > &pairList, unsigned begin,
                       unsigned end);
        void merge(std::list<std::pair<int, int> > &pairList, unsigned begin,
                   unsigned middle, unsigned end);
        void sortPairs();
        void sortValuesWithinPairs();

        std::list<int> shuffled;
        std::list<std::pair<int, int> > pairs;
        std::list<int> mainChain;
        std::list<int> pend;
        std::list<int> jacobsthalNumbers;
        std::list<int> positions;
    };

    class PmergeMeVector
    {
      public:
        PmergeMeVector(void);
        PmergeMeVector(const PmergeMeVector &src);
        ~PmergeMeVector(void);

        void sort(const char *const *argv);

        PmergeMeVector &operator=(const PmergeMeVector &rhs);

      private:
        unsigned binarySearch(const std::vector<int> &list, ssize_t begin,
                              ssize_t end, int search);
        void createMainAndPendList();
        void createPairsList();
        void createShuffledList(const char *const *argv);
        void generatPositions();
        void generateJacobInsertionSequence();
        void insertPendIntoMainChain();
        int jacobsthal(int n);
        void mergeSort(std::list<std::pair<int, int> > &pairList, unsigned begin,
                       unsigned end);
        void merge(std::list<std::pair<int, int> > &pairList, unsigned begin,
                   unsigned middle, unsigned end);
        void sortPairs();
        void sortValuesWithinPairs();

        std::vector<int> shuffled;
        std::list<std::pair<int, int> > pairs;
        std::vector<int> mainChain;
        std::vector<int> pend;
        std::vector<int> jacobsthalNumbers;
        std::vector<int> positions;
    };
};

#endif
