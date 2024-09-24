#include "ScalarConverter.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>


ScalarConverter::ScalarConverter(void)
{
#ifdef DEBUG
    std::cout << "ScalarConverter: overloaded default constructor called" << std::endl;
#endif
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter)
{
#ifdef DEBUG
    std::cout << "ScalarConverter: overloaded copy constructor called" << std::endl;
#endif
    (void)scalarConverter;
}

ScalarConverter::~ScalarConverter(void)
{
#ifdef DEBUG
    std::cout << "ScalarConverter: overloaded destructor called" << std::endl;
#endif
}
    
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarConverter)
{
#ifdef DEBUG
    std::cout << "ScalarConverter: overloaded assignment operator called" << std::endl;
#endif
    (void)scalarConverter;
    return *this;
}

const char * ScalarConverter::InvalidStringException::what() const throw()
{
    return ("string cannot be converted to a scalar type.");
}

void ScalarConverter::convert(const std::string &str) throw (ScalarConverter::InvalidStringException)
{
    eStringType strType = getStringScalarType(str);
    if (strType == INVALID)
        throw (ScalarConverter::InvalidStringException());
    printStringScalarTypes(str, strType);
}

/**
 * getStringScalarType - check whether a string can be converted to a primitive
 *                       type (char, int, float or double)
 *
 * It is worth remembering that if the string is a word representing special
 * values such as +inf or nan, for example, it will return a value other 
 * than INVALID for these words.
 * 
 * i.e: '10' return INT, 10.0 return DOUBLE, nan return NAN
 *
 * Return:
 *  A value inside the enum eStringType.
 *
 * See:
 *  enum eStringType
 */
eStringType getStringScalarType(const std::string &str)
{
    if (isStrAChar(str) == 1)
        return (CHAR_DISPLAYABLE);
    if (isStrAChar(str) == -1)
    {
        return (CHAR_NON_DISPLAYABLE);
    }
	if (isStrAInt(str))
        return (INT);
	if (isStrAFloat(str))
        return (FLOAT);
	if (isStrADouble(str))
        return (DOUBLE);
	if (isStrAPositiveInfinity(str))
        return (POS_INF);
	if (isStrANegativeInfinity(str))
        return (NEG_INF);
	if (isSrtNotANumber(str))
        return (NAN);
    return (INVALID);
}

void printStringScalarTypes(const std::string &str, eStringType strType)
{
    if (strType == CHAR_DISPLAYABLE || strType == CHAR_NON_DISPLAYABLE)
        return (printValueChar(str, strType));
    if (strType == INT)
        return (printValueInt(str));
    if (strType == FLOAT)
        return (printValueFloat(str));
    if (strType == DOUBLE)
        return (printValueDouble(str));
    if (strType == POS_INF)
        return (printValuePositiveInfinity(str));
    if (strType == NEG_INF)
        return (printValueNegativeInfinity(str));
    if (strType == NAN)
        return (printValueNotANumber(str));
}

/**
 * isStrChar - check if a string is a valid char
 *
 * Return:
 *   0 - if the string isn't a char
 *   1 - if the string is a pritable char
 *  -1 - if the string is a non printable char
 */
int isStrAChar(const std::string str)
{
    if (str.length() != 1)
        return (0);
    if (std::isdigit(str[0]))
        return (0);
    if (std::isprint(str[0]))
        return (1);
    return (-1);
}
bool isStrAInt(const std::string str)
{
    char *strEnd;
    long _long = std::strtol(str.c_str(), &strEnd, 10);

    if (*strEnd != '\0')
        return (false);
    if (_long < std::numeric_limits<int>::min() || _long > std::numeric_limits<int>::max())
        return (false);
    return(true);
}

bool isStrAFloat(const std::string str)
{
    char *strEnd;
    float _float;

    _float = std::strtof(str.c_str(), &strEnd);
    if (*strEnd != 'f')
        return (false);
    if (*(strEnd + 1) != '\0')
        return (false);
    if (_float == std::numeric_limits<float>::infinity() || ((_float * -1) == std::numeric_limits<float>::infinity()))
        return (false);
    if (str == "nanf")
        return (false);
    return (true);
}

bool isStrADouble(const std::string str)
{
    char *strEnd;
    double _double;

    if (str.find('.') == std::string::npos)
        return (false);
    _double = std::strtod(str.c_str(), &strEnd);
    if (_double == std::numeric_limits<double>::infinity() || ((_double * -1) == std::numeric_limits<double>::infinity()))
        return (false);
    if (_double == std::numeric_limits<double>::quiet_NaN())
        return (false);
    if (*strEnd != '\0')
    {
        return (false);
    }
	return(true);
}

bool isStrAPositiveInfinity(const std::string str)
{
    if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
        return (true);
    return (false);
}

bool isStrANegativeInfinity(const std::string str)
{
    if (str == "-inf" || str == "-inff")
        return (true);
    return (false);
}

bool isSrtNotANumber(const std::string str)
{
    if (str == "nan" || str == "nanf")
        return (true);
    return (false);
}



void printValueChar(const std::string str, eStringType strType)
{
    (void) strType;
    char    _char = str[0];
    int     _int = static_cast<int>(_char);
    float   _float  = static_cast<float>(_char);
    double  _double = static_cast<double>(_char);

    printAllValidValues(_char, _int, _float, _double, 1);
}

void printValueInt(const std::string str)
{
    int     _int =  static_cast<int>(std::strtol(str.c_str(), NULL, 10));
    char    _char = static_cast<char>(_int);
    float   _float  = static_cast<float>(_int);
    double  _double = static_cast<double>(_int);

    printAllValidValues(_char, _int, _float, _double, 1);
}

void printValueFloat(const std::string str)
{
    float   _float  = std::strtof(str.c_str(), NULL);
    char    _char = static_cast<char>(_float);
    int     _int = static_cast<int>(_float);
    double  _double = static_cast<double>(_float);

    unsigned int decimal_precision;
    std::string::size_type point = str.find('.');

    if (point == std::string::npos)
        decimal_precision = 1;
    else
        decimal_precision = str.length() - point - 2;

    printAllValidValues(_char, _int, _float, _double, decimal_precision);
}

void printValueDouble(const std::string str)
{
    double  _double = std::strtod(str.c_str(), NULL);
    float   _float  = static_cast<float>(_double); 
    char    _char = static_cast<char>(_double);
    int     _int = static_cast<int>(_double);

    unsigned int decimal_precision = str.length() - str.find('.') - 1;

    printAllValidValues(_char, _int, _float, _double, decimal_precision);
}

void printValuePositiveInfinity(const std::string str)
{
    (void)str;

    double  _double = std::numeric_limits<double>::infinity();
    float   _float  = std::numeric_limits<float>::infinity();
    
    //print the char
    std::cout << "char\t: impossible" << std::endl;
    //print the int
    std::cout << "int\t: impossible" << std::endl;

    //print the float
    std::cout << "float\t: " << _float << "f" << std::endl;

    //print the double
    std::cout << "double\t: " << _double << std::endl;
}

void printValueNegativeInfinity(const std::string str)
{
    (void)str;

    double  _double = std::numeric_limits<double>::infinity() * -1;
    float   _float  = std::numeric_limits<float>::infinity() * -1;
    
    //print the char
    std::cout << "char\t: impossible" << std::endl;
    //print the int
    std::cout << "int\t: impossible" << std::endl;

    //print the float
    std::cout << "float\t: " << _float << "f" << std::endl;

    //print the double
    std::cout << "double\t: " << _double << std::endl;
}

void printValueNotANumber(const std::string str)
{
    (void)str;

    double  _double = std::numeric_limits<double>::quiet_NaN();
    float   _float  = std::numeric_limits<float>::quiet_NaN();
    
    //print the char
    std::cout << "char\t: impossible" << std::endl;
    //print the int
    std::cout << "int\t: impossible" << std::endl;

    //print the float
    std::cout << "float\t: " << _float << "f" << std::endl;

    //print the double
    std::cout << "double\t: " << _double << std::endl;
}

void printAllValidValues(char _char, int _int, float _float, double _double, unsigned decimal_precision)
{
    if(_int <= 255)
    {
        if(std::isprint(_char))
            std::cout << "char\t: " << _char << std::endl;
        else
            std::cout << "char\t: Non displayable" << std::endl;
    }
    else
        std::cout << "char\t: impossible" << std::endl;

    //print the int
    std::cout << "int\t: " << _int << std::endl;

    //print the float
    std::cout << "float\t: " << std::fixed << std::setprecision(decimal_precision) << _float;
    std::cout << "f" << std::endl;

    //print the double
    std::cout << "double\t: " << _double << std::endl;
}
