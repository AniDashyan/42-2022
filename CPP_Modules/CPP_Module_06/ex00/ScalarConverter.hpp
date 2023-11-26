#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

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
        static void convert(const std::string& literal); // Read more about static functions
        // static bool convertToChar(double literal);
        // static bool convertToInt(double literal);
        // static bool convertToFloat(double literal);
        // static bool convertToDouble(const std::string& literal);
};

#endif