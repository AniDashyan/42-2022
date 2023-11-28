#include "ScalarConverter.hpp"
// Global headers
#include <iostream> // cout
#include <climits> // INT_MAX and INT_MIN
#include <cstdlib> // strtod()
#include <stdexcept> // exceptions
#include <cmath> // +/- HUGE_VAL
#include <cctype> // isdigit
#include <iomanip> // preventing cout to use the scientific notation
#include <cerrno> // errno

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
        std::cout << "double: " << num << std::endl;
    }
    catch (std::exception& e)
    {
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
    std::cout << "str after erases:" << literal << std::endl;

    // will contain the double representation of a string
    double result;
    if (literal.empty())
        throw std::invalid_argument("Error: Literal is empty");
    else if (literal.length() == 1 && !isdigit(literal[0])) // char 
        result = literal[0];
    // checks for pseudo literals
    else if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "inff" || literal == "+inff" || literal == "-inff")
        throw std::out_of_range(literal + " is out of range");
    else if (literal == "nan" || literal == "nanf")
        throw std::out_of_range(literal + " is nan");
    else if (isdigit(literal[0]) || ((literal[0] == '-' || literal[0] == '+') && isdigit(literal[1])))
    {
        size_t dotPos = literal.find(".");
        if (!isdigit(literal[dotPos + 1]))
            throw std::invalid_argument("Error: There should be a number after '.'");
        else if (!isInDecimalNotation(literal))
            throw std::invalid_argument("Error: Literal has to be in decimal notation");

        char* endPtr;
        result = std::strtod(literal.c_str(), &endPtr);
        std::string end(endPtr);
        std::cout << "end: " << end << std::endl;
        if (!end.empty())
        {
            if (end.length() == 1)
            {
                if (end != "f")
                    throw std::invalid_argument("Error: Invalid input");
            }
            else
                throw std::invalid_argument("Error: Inavlid input");
        }
        else if (errno == ERANGE && (result == HUGE_VAL || result == -HUGE_VAL)) {
            throw std::out_of_range("Value outside the range representable by double.");
        } 
        else if (errno == ERANGE) {
            throw std::range_error("Value out of range representable by double.");
        }
        else if (result == 0.0 && (literal != "0" || literal != "0.0"))
            throw std::invalid_argument("Error: Conversion cannot be done");
    }
    else
    {
        throw std::invalid_argument("Inavlid input");
    }
    return (result);
}

bool isInDecimalNotation(std::string& literal) {
    (void)literal;
    return (false);
}

void convertToChar(double literal) {}
void convertToInt(double literal) {}
void convertToFloat(double literal) {}
void convertToDouble(double literal) {}