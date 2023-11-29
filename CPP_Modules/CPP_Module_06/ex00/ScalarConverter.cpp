#include "ScalarConverter.hpp"
// Global headers
#include <iostream> 
#include <limits> 
#include <cstdlib>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cerrno>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {

}

void ScalarConverter::convert(std::string& literal) {
    try {
        double num = parsing(literal);
        convertToChar(num);
        convertToInt(num);
        convertToFloat(num);
        convertToDouble(num);
    }
    catch (std::exception& e)
    {
        std::string pseudoStr = e.what();
        if (pseudoStr.compare("nan") == 0 || pseudoStr.compare("nanf") == 0)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (pseudoStr[0] == '+' || pseudoStr[0] == 'i')
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        }
        else if (literal[0] == '-' && literal[1] == 'i')
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else
            std::cout << e.what() << std::endl;
    }
}

double parsing(std::string& literal) {
    // checking if literal is empty
    if (literal.empty())
        throw std::invalid_argument("Error: Literal is empty");

    // clear spaces from start and end
    literal.erase(0, literal.find_first_not_of(WHITESPACES));
    literal.erase(literal.find_last_not_of(WHITESPACES) + 1);

    // will contain the double representation of a string
    double result;
    if (literal.empty())
        throw std::invalid_argument("Error: Literal is empty");
    else if (literal.length() == 1 && !isdigit(literal[0])) // char 
        result = literal[0];
    // checks for pseudo literals
    else if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "inff" || literal == "+inff" || literal == "-inff")
        throw std::out_of_range(literal);
    else if (literal == "nan" || literal == "nanf")
        throw std::out_of_range(literal);
    else if (isdigit(literal[0]) || ((literal[0] == '-' || literal[0] == '+') && isdigit(literal[1])))
    {
        size_t dotPos = literal.find(".");
        if (dotPos != std::string::npos && !isdigit(literal[dotPos + 1]))
            throw std::invalid_argument("Error: There should be a number after '.'");
        else if (isInScientificNotation(literal))
            throw std::invalid_argument("Error: Literal has to be in decimal notation");

        char* endPtr;
        result = std::strtod(literal.c_str(), &endPtr);
        std::string end(endPtr);
        if (!end.empty())
        {
            if (end.length() == 1)
            {
                if (end != "f")
                    throw std::invalid_argument("Error: Invalid literal");
            }
            else
                throw std::invalid_argument("Error: Inavlid literal");
        }
        else if (errno == ERANGE && (result == HUGE_VAL || result == -HUGE_VAL)) {
            throw std::out_of_range("Value outside the range representable by double.");
        } 
        else if (errno == ERANGE) {
            throw std::range_error("Value out of range representable by double.");
        }
        else if (result == 0.0 && (literal != "0" && literal != "0.0"))
            throw std::invalid_argument("Error: Conversion cannot be done");
    }
    else
    {
        throw std::invalid_argument("Inavlid literal");
    }
    return (result);
}

bool isInScientificNotation(std::string& literal) {
    size_t found = literal.find_first_of("eE");
    if (found == std::string::npos) {
        return false;
    }

    std::string beforeE = literal.substr(0, found);
    std::string afterE = literal.substr(found + 1);

    bool validBeforeE = !beforeE.empty() &&
                        (beforeE.find_first_not_of("0123456789.-+") == std::string::npos);

    bool validAfterE = !afterE.empty() &&
                       (afterE.find_first_not_of("0123456789+-") == std::string::npos);

    return (validBeforeE && validAfterE);

}

void convertToChar(double literal) {
    try {
        if (literal < std::numeric_limits<char>::min() || literal > std::numeric_limits<char>::max())
            throw std::range_error("char: impossible");
        else if (!isprint(literal))
            throw std::runtime_error("char: Non displayable");
        else
            std::cout << "char: '" << static_cast<char>(literal) << "'" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void convertToInt(double literal) {
    try {
        if (literal > std::numeric_limits<int>::max() || literal < std::numeric_limits<int>::min())
            throw std::out_of_range("int: impossible");
        else
            std::cout << "int: " << static_cast<int>(literal) << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
}

void convertToFloat(double literal) {
    try {
        int decimalCount = countDecimalDigit(literal);
        if (literal > std::numeric_limits<float>::max())
            throw std::out_of_range("float: inf");
        else
            std::cout << std::fixed << std::setprecision(decimalCount) << "float: " << static_cast<float>(literal) << "f" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void convertToDouble(double literal) {
    try {
        int decimalCount = countDecimalDigit(literal);
        if (literal > std::numeric_limits<double>::max())
            throw std::out_of_range("double: inf");
        else
            std::cout << std::fixed << std::setprecision(decimalCount) << "double:" << literal << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int countDecimalDigit(double number) {
    std::stringstream s;
    s << number;
    std::string doubleAsStr = s.str();
    size_t dotPos = doubleAsStr.find(".");
    if (dotPos == std::string::npos)
        return (1);
    return (doubleAsStr.length() - dotPos - 1);
}