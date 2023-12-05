#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#define WHITESPACES  " \r\n\t\v\f"

#include <string>

class ScalarConverter {
    private:
        // By making ctr, copy-ctr, copy =operator private we make the class not instantiable and copyable
        // We do this because class doesn't need anything at all
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        // The convert() method is static because we made class non instantiable
        static void convert(std::string& literal);
};

std::string parsing(std::string& literal);
bool isInScientificNotation(std::string& literal);
bool isChar(std::string& literal);
bool isInt(std::string& literal);
bool isFloat(std::string& literal);
bool isDouble(std::string& literal);
int countDecimalDigits(std::string& number);
void convertToChar(std::string& literal);
void convertToInt(std::string& literal);
void convertToFloat(std::string& literal);
void convertToDouble(std::string& literal);
#endif