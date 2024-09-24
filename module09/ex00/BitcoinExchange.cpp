#include "BitcoinExchange.hpp"

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
  if (this == &src) return *this;
  this->values = src.values;
  return *this;
}

bool BitcoinExchange::createPair(std::string line, std::string delimiter,
                                 std::pair<std::string, float> &pair) {
  std::string **dateAndValue = 0;
  bool isPairOk = false;
  long date = 0;
  float price = 0;

  if (line.empty()) {
    std::cout << "Error: empty line" << std::endl;
    return false;
  }

  // check if the date and value pair are valid
  if (split(line, delimiter, dateAndValue)) return ERR_MEMORY;
  if ((splitSize(dateAndValue) != 2) || (*(dateAndValue[0])).empty() ||
      (*(dateAndValue[1])).empty()) {
    std::cout << "Error: bad input => " << line << std::endl;
    goto returnz;
  }

  // check if date (year, month and day) is valid
  isPairOk = (isValidDate(*(dateAndValue[0])) == OK);
  if (!isPairOk) {
    std::cout << "Error: date is invalid => " << *(dateAndValue[0])
              << std::endl;
    goto returnz;
  }

  // check if value is valid
  isPairOk = (isValidValue(*(dateAndValue[1]), false) == OK);
  if (!isPairOk) {
    std::cout << "Error: price is invalid => " << *(dateAndValue[1])
              << std::endl;
    goto returnz;
  }

  date = strDateToLong(*(dateAndValue[0]));
  price = std::strtof((*(dateAndValue[1])).c_str(), 0);
  if (price < 0) {
    std::cout << "Error: not a positive number" << std::endl;
    isPairOk = false;
    goto returnz;
  }

  pair = std::make_pair(*(dateAndValue[0]), price);
  isPairOk = true;

returnz:
  if (dateAndValue) splitFree(dateAndValue);
  return isPairOk;
}

int BitcoinExchange::checkDataBaseFile(const std::string databaseFile) {
  std::ifstream ifsDataBase;
  if (openFile(databaseFile, ifsDataBase)) return 1;
  if (loadDataBase(ifsDataBase)) return 1;
  return OK;
}

int BitcoinExchange::checkInputFile(const std::string inputFile) {
  std::ifstream ifsInput;
  std::string strLine;
  std::pair<std::string, float> pair;
  std::map<std::string, float>::iterator pairDatabase;

  if (openFile(inputFile, ifsInput)) return 1;

  getLine(ifsInput, strLine);
  if (strLine != "date | value") std::cout << "invalid header" << std::endl;

  for (size_t count = 1; getLine(ifsInput, strLine); count++) {
    if (!createPair(strLine, " | ", pair)) continue;
    if (pair.second > MAX_VALUE) {
      std::cout << "Error: too large a number" << std::endl;
      continue;
    }
    pairDatabase = getValidDatePair(values, pair.first);
    if (pairDatabase == values.end()) {
      std::cout << "Error: the date(" << pair.first
                << ") is before the existence of bitcoin" << std::endl;
      continue;
    }
    std::cout << pair.first << " => " << pair.second << " = "
              << (pair.second * pairDatabase->second) << std::endl;
  }

  return OK;
}

int BitcoinExchange::getLine(std::istream &isStream, std::string &output) {
  if (isStream.eof()) return 0;
  std::getline(isStream, output);
  if (isStream.eof() && output.empty()) return 0;
  return 1;
}

int BitcoinExchange::isValidDate(const std::string &strDateYYYYMMDD) {
  std::string **dateMembers = 0;
  int intReturn = OK;

  if (split(strDateYYYYMMDD, "-", dateMembers)) return ERR_MEMORY;

  if (splitSize(dateMembers) != 3) {
    intReturn = ERR_DATE_INVALID;
    goto returnz;
  }
  if (!isStrAInt(*(dateMembers[0])) || !isStrAInt(*(dateMembers[1])) ||
      !isStrAInt(*(dateMembers[2]))) {
    intReturn = ERR_DATE_INVALID;
    goto returnz;
  }
  if (!isMonthAndDayValid(*(dateMembers[0]), *(dateMembers[1]),
                          *(dateMembers[2]))) {
    intReturn = ERR_DATE_INVALID;
    goto returnz;
  }

returnz:
  if (dateMembers) splitFree(dateMembers);
  return intReturn;
}

int BitcoinExchange::isValidValue(const std::string &strValue,
                                  bool useMaxValue) {
  if (strValue.empty()) return ERR_VALUE_INVALID;
  if (!isStrAFloat(strValue)) return ERR_VALUE_INVALID;
  float floatValue = std::strtof(strValue.c_str(), 0);
  if (useMaxValue && floatValue > 1000) return ERR_VALUE_MAX_OVERFLOW;
  return OK;
}

int BitcoinExchange::loadDataBase(std::ifstream &ifsDatabase) {
  std::string strLine;
  std::pair<std::string, float> pair;
  std::map<std::string, float>::iterator it;

  // check header file
  if (!getLine(ifsDatabase, strLine)) return 1;
  if (strLine != "date,exchange_rate") {
    std::cout << "The data.csv file header is corrupt. The file is invalid"
              << std::endl;
    std::cout << "[" << strLine << "]" << std::endl;
    return 1;
  }

  while (getLine(ifsDatabase, strLine)) {
    bool isLineValid = createPair(strLine, ",", pair);
    if (!isLineValid) {
      std::cout << "The data.csv is corrupt. The file is invalid" << std::endl;
      return 1;
    }
    // check if the date already exists
    it = values.find(pair.first);
    if (it != values.end()) {
      std::cout << "The date: " << pair.first << "already exists" << std::endl;
      return 1;
    }
    values.insert(pair);
  }
  return 0;

  std::cout << "map size: " << values.size() << std::endl;

  for (std::map<std::string, float>::iterator it = values.begin();
       it != values.end(); ++it) {
    std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
  }

  return 0;
}

int BitcoinExchange::openFile(const std::string &fileName, std::ifstream &ifs) {
  ifs.open(fileName.c_str());
  if (!ifs.is_open()) {
    std::string strError = "Unable to open file " + fileName;
    showErrno(strError);
    return 1;
  }
  if (ifs.peek() == std::ifstream::traits_type::eof()) {
    std::string strError = "The file " + fileName + " is empty.";
    showError(strError);
    return 1;
  }
  return 0;
}

void BitcoinExchange::showError(const std::string &message) const {
  std::cout << "Error: " << message << std::endl;
}

void BitcoinExchange::showErrno(const std::string &message) const {
  std::cout << "Error: ";
  if (message.size()) std::cout << message << ": ";
  std::cout << strerror(errno) << std::endl;
}

long BitcoinExchange::strDateToLong(const std::string &strYYYYMMDD) const {
  std::string **dateMembers = 0;

  if (split(strYYYYMMDD, "-", dateMembers)) return 0;

  int intYear =
      static_cast<int>(std::strtol((*(dateMembers[0])).c_str(), 0, 10));
  int intMonth =
      static_cast<int>(std::strtol((*(dateMembers[1])).c_str(), 0, 10));
  int intDay =
      static_cast<int>(std::strtol((*(dateMembers[2])).c_str(), 0, 10));

  splitFree(dateMembers);
  return (intYear * 10000 + intMonth * 100 + intDay);
}
