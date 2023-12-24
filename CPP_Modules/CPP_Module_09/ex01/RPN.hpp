#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN {
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void calculate(std::string line);
    private:
        std::string clearSpaces(std::string line);
        double add(double num1, double num2);
        double subtract(double num1, double num2);
        double multiply(double num1, double num2);
        static bool isSpace(char a, char b);
        static bool isOperator(char op);
        double divide(double num1, double num2);
        double operation(double num1, double num2, char operation);
    private:
        std::stack<double> m_stack;
};

#endif