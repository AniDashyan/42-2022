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
        static void convert(std::string& literal); // Read more about static functions
};

double parsing(std::string& literal);
bool isInScientificNotation(std::string& literal);
int countDecimalDigit(double number);
void convertToChar(double literal);
void convertToInt(double literal);
void convertToFloat(double literal);
void convertToDouble(double literal);
#endif