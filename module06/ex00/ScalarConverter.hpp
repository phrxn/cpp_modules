#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

typedef enum eStringType
{
    INVALID = 1,
    CHAR_DISPLAYABLE,
    CHAR_NON_DISPLAYABLE,
    INT,
    FLOAT,
    DOUBLE,
    POS_INF,
    NEG_INF,
    NAN
}   eStringType;

class ScalarConverter
{
    // ---------- constructor(s) and destructor ----------
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &scalarConverter);
        ~ScalarConverter(void);
    
    // ---------- functions ----------
    public:
        static void convert(const std::string &str) throw (ScalarConverter::InvalidStringException);

    private:
        //operator(s) overload
        ScalarConverter &operator=(const ScalarConverter &scalarConverter);

    // ---------- nested class(es) ----------
    public:
        class InvalidStringException : public std::exception
        {
            virtual const char * what() const throw();
        };
};

eStringType getStringScalarType(const std::string &str);
void printStringScalarTypes(const std::string &str, eStringType strType);

// check string type
int isStrAChar(const std::string str);
bool isStrAInt(const std::string str);
bool isStrAFloat(const std::string str);
bool isStrADouble(const std::string str);
bool isStrAPositiveInfinity(const std::string str);
bool isStrANegativeInfinity(const std::string str);
bool isSrtNotANumber(const std::string str);

//print the messages
void printValueChar(const std::string str, eStringType strType);
void printValueInt(const std::string str);
void printValueFloat(const std::string str);
void printValueDouble(const std::string str);
void printValuePositiveInfinity(const std::string str);
void printValueNegativeInfinity(const std::string str);
void printValueNotANumber(const std::string str);

void printAllValidValues(char _char, int _int, float _float, double _double, unsigned decimal_precision);
#endif
