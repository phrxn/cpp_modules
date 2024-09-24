#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <ctime>
#include <map>
#include <string>

class BitcoinExchange {
 public:
  static const int MAX_VALUE = 1000;
  // status
  static const int OK = 0;
  static const int ERR_MEMORY = 1;
  static const int ERR_LINE_EMPTY = 2;
  static const int ERR_LINE_INVALID = 3;
  static const int ERR_VALUE_INVALID = 4;
  static const int ERR_VALUE_MAX_OVERFLOW = 5;
  static const int ERR_DATE_INVALID = 6;
  static const int ERR_DUPLICATE_DATE = 7;

  BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange &src);
  ~BitcoinExchange(void);

  // read a csv inputFile and show the prices
  int checkDataBaseFile(const std::string databaseFile);
  int checkInputFile(const std::string inputFile);

  BitcoinExchange &operator=(const BitcoinExchange &src);

 private:
  bool createPair(std::string line, std::string delimiter,
                  std::pair<std::string, float> &pair);
  int getLine(std::istream &isStream, std::string &output);
  int isValidDate(const std::string &strDateYYYYMMDD);
  int isValidValue(const std::string &strValue, bool useMaxValue);
  int loadDataBase(std::ifstream &ifsDatabase);
  int openFile(const std::string &fileName, std::ifstream &ifs);
  void showErrno(const std::string &message) const;
  void showError(const std::string &message) const;
  long strDateToLong(const std::string &strYYYYMMDD) const;

  std::map<std::string, float> values;
};

void splitFree(std::string **&free);
size_t splitSize(std::string **&split);
int split(const std::string &toSplit, const std::string &s,
          std::string **&output);

bool isStrAInt(const std::string &str);
bool isStrAFloat(const std::string &str);
bool isMonthAndDayValid(const std::string &year, const std::string &month,
                        const std::string &day);

template <typename Map, typename Key>
typename Map::iterator getValidDatePair(Map &map, const Key &key) {
  typename Map::iterator it;

  if (map.empty()) return map.end();
  it = map.lower_bound(key);
  if (it == map.end()) return --it;
  if (it == map.begin() && key != it->first) return map.end();
  if (key == it->first) return it;
  return --it;
}

#endif
