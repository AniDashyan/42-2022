#include "ScalarConverter.hpp"

#include <iostream>
#include <limits>
#include <cfloat>
#include <cstdlib>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cerrno>
#include <cassert>

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
        std::string num = parsing(literal);
        if (isChar(num))
            convertToChar(num);
        else if (isInt(num))
            convertToInt(num);
        else if (isFloat(num))
            convertToFloat(num);
        else if (isDouble(num))
            convertToDouble(num);
    }
    catch (std::exception& e)
    {
        std::string pseudoStr = e.what();
        if (pseudoStr[0] == '+' || pseudoStr[0] == 'i')
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
        else if (pseudoStr.compare("nan") == 0 || pseudoStr.compare("nanf") == 0)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else
            std::cout << e.what() << std::endl;
    }
}

std::string parsing(std::string& literal) {
    // checking if literal is empty
    if (literal.empty())
        throw std::invalid_argument("Error: Literal is empty");

    // clear spaces from start and end
    literal.erase(0, literal.find_first_not_of(WHITESPACES));
    literal.erase(literal.find_last_not_of(WHITESPACES) + 1);

    // will contain the double representation of a string
    double result;
    if (literal.empty())
        throw std::invalid_argument("Error: Literal is empty after clearing spaces");
    else if (literal.length() == 1 && !isdigit(literal[0])) // char 
        return (literal);
    // checks for pseudo literals
    else if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "inff" || literal == "+inff" || literal == "-inff")
        throw std::out_of_range(literal);
    else if (literal == "nan" || literal == "nanf")
        throw std::domain_error(literal);
    else if (isdigit(literal[0]) || ((literal[0] == '-' || literal[0] == '+') && isdigit(literal[1])))
    {
        if ((literal[0] == '-' || literal[0] == '+') && literal[1] == '0')
            throw std::invalid_argument("Error: Invalid input");
        // checking if there is a number after "."
        size_t dotPos = literal.find(".");
        if (dotPos != std::string::npos && !isdigit(literal[dotPos + 1]))
            throw std::invalid_argument("Error: There should be a number after '.'");
        else if (isInScientificNotation(literal))
            throw std::invalid_argument("Error: Literal has to be in decimal notation");

        char* endPtr;
        result = std::strtod(literal.c_str(), &endPtr);
        std::string end(endPtr); // making endPtr a string object
        if (!end.empty() && (end.length() != 1 || (end.length() == 1 && end != "f")))
            throw std::invalid_argument("Error: Inavlid literal");
        else if (errno == ERANGE)
            throw std::range_error("Error: Value out of range representable by double.");
        else if (result == 0.0 && (literal != "0" && literal != "0.0"))
            throw std::invalid_argument("Error: Conversion cannot be done");
    }
    else
        throw std::invalid_argument("Error: Inavlid input");

    return (literal);
}

bool isChar(std::string& literal) {
    return (literal.length() == 1 && !isdigit(literal[0]));
}

bool isInt(std::string& literal) {
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (literal[i] == '0' && (literal.length() - i) > 1)
        return (false);
    for (; i < literal.length(); i++)
        if (!isdigit(literal[i]))
            return (false);

    return (true);
}

bool isDouble(std::string& literal) {
    size_t i = 0;
    bool hasDot = false;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    for (; i < literal.length(); i++)
    {
        if (!isdigit(literal[i]) && literal[i] != '.')
            return (false);
        if (literal[i] == '.')
            hasDot = true;
    }
    return (hasDot);
}

bool isFloat(std::string& literal) {
    size_t i = 0;
    bool hasDot = false;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    for (; i < literal.length(); i++)
    {
        if ((!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f'))
            return (false);
        if (literal[i] == '.')
            hasDot = true;
        if (literal[i] == 'f' && i != literal.length() - 1)
            return (false);
    }
    if (literal.find("f") == std::string::npos)
        return (false);

    return (hasDot);
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

void convertToChar(std::string& literal) {
    char symbol = literal[0];
    if (symbol < std::numeric_limits<char>::min() || symbol > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(symbol))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << symbol << "'" << std::endl;

    std::cout << "int: " << static_cast<int>(symbol) << std::endl;
    std::cout << std::fixed << std::setprecision(countDecimalDigits(literal)) << "float: " << static_cast<float>(symbol) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(symbol) << std::endl;
    
}

void convertToInt(std::string& literal) {
    double result = std::strtod(literal.c_str(), NULL);
    if (result > std::numeric_limits<char>::max() || result < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(result))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(result) << std::endl;

    if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(result) << std::endl;

    std::cout << std::fixed << std::setprecision(countDecimalDigits(literal)) << "float: " << static_cast<float>(result) << "f" << std::endl;
    std::cout <<  "double: " << result << std::endl;
}

// When defining float without suffix 'f' it defines it as a double by default
void convertToFloat(std::string& literal) {
    double result = std::strtod(literal.c_str(), NULL);
    if (result > std::numeric_limits<char>::max() || result < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(result))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(result) << std::endl;

    if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(result) << std::endl;

    if (result > FLT_MAX || result < -FLT_MAX)
        std::cout << "float: impossible";
    else
        std::cout << std::fixed << std::setprecision(countDecimalDigits(literal)) << "float: " << static_cast<float>(result) << "f" << std::endl;

    std::cout << "double: " << result << std::endl;
}

void convertToDouble(std::string& literal) {
    double result = std::strtod(literal.c_str(), NULL);
    if (result > std::numeric_limits<char>::max() || result < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(result))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(result) << std::endl;

    if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(result) << std::endl;

    if (result > FLT_MAX || result < -FLT_MAX)
        std::cout << "float: impossible";
    else
        std::cout << std::fixed << std::setprecision(countDecimalDigits(literal)) << "float: " << static_cast<int>(result) << "f" << std::endl;

    std::cout << "double: " << result << std::endl;
}

int countDecimalDigits(std::string& number) {
    size_t dotPos = number.find(".");
    if (dotPos == std::string::npos)
        return (1);
    return (number.length() - dotPos - 1);
}