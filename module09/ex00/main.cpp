#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "BitcoinExchange.hpp"

int checkParameters(int argc, char **argv) {
  (void)argv;
  if (argc != 2) {
    std::cout << "Usage: ./btc <input file>" << std::endl;
    return 1;
  }
  return 0;
}

void splitFree(std::string **&free) {
  if (!free) return;
  for (size_t count = 0; free[count] != 0; ++count) delete free[count];
  delete[] free;
  free = 0;
}

size_t splitSize(std::string **&split) {
  size_t count = 0;
  while (split[count]) count++;
  return count;
}

int split(const std::string &toSplit, const std::string &s,
          std::string **&output) {
  size_t count_strings = 1;
  std::string::size_type start = 0;

  if (toSplit.empty()) return 1;

  std::string::size_type end = toSplit.find(s);
  while (end != std::string::npos) {
    count_strings++;
    start = end + s.length();
    end = toSplit.find(s, start);
  }
  output = new std::string *[count_strings + 1];
  output[count_strings] = 0;

  count_strings = 0;
  start = 0;
  end = toSplit.find(s);

  while (end != std::string::npos) {
    output[count_strings++] =
        new std::string(toSplit.substr(start, end - start));
    start = end + s.length();
    end = toSplit.find(s, start);
  }
  output[count_strings] = new std::string(toSplit.substr(start));
  return 0;
}

void printSlip(std::string **arrayS) {
  size_t countStrings = 0;
  while (arrayS[countStrings]) {
    std::cout << *(arrayS[countStrings]) << std::endl;
    countStrings++;
  }
}

bool isStrAInt(const std::string &str) {
  char *strEnd = 0;
  if (str.empty()) return false;

  long _long = std::strtol(str.c_str(), &strEnd, 10);

  if (*strEnd != '\0') return (false);
  if (_long < std::numeric_limits<int>::min() ||
      _long > std::numeric_limits<int>::max())
    return (false);
  return (true);
}

bool isStrAFloat(const std::string &str) {
  char *strEnd = 0;
  float _float;

  if (str.empty()) return false;

  _float = std::strtof(str.c_str(), &strEnd);

  if (*strEnd != '\0') return (false);
  if (_float == std::numeric_limits<float>::infinity() ||
      ((_float * -1) == std::numeric_limits<float>::infinity()))
    return (false);
  if (str == "nanf") return (false);
  return (true);
}

bool isMonthAndDayValid(const std::string &year, const std::string &month,
                        const std::string &day) {
  if (!isStrAInt(month)) return false;
  if (!isStrAInt(day)) return false;

  int intMonth = static_cast<int>(std::strtol(month.c_str(), NULL, 10));

  // check if month is valid
  if (intMonth < 1 || intMonth > 12) return false;

  // check if month day is valid
  int monthDaysSize[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int intYear = static_cast<int>(std::strtol(year.c_str(), NULL, 10));
  if ((intYear % 4 == 0) && ((intYear % 100 != 0) || (intYear % 400 == 0)))
    monthDaysSize[1] = 29;
  int intDay = static_cast<int>(std::strtol(day.c_str(), NULL, 10));
  if (intDay < 1 || intDay > monthDaysSize[intMonth - 1]) return false;

  return true;
}

int main(int argc, char **argv) {
  BitcoinExchange bitcoinExchange;

  if (checkParameters(argc, argv)) return 1;
  if (bitcoinExchange.checkDataBaseFile("data.csv")) return 1;
  bitcoinExchange.checkInputFile(std::string(argv[1]));

  return 0;
}
