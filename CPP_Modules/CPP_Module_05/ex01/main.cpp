#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat defb1;
        std::cout << defb1 << std::endl;

        Bureaucrat b1("Jack", 15);
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;

        Form defform;
        std::cout << defform << std::endl;

        Form form1("Hack", 40, 30);
        std::cout << form1 << std::endl;

        Form form2(defform);
        std::cout << form2 << std::endl;
        form2.beSigned(b1);
        std::cout << form2 << std::endl;


        b1.signForm(form1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}       