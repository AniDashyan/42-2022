#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm *makeForm(std::string formName, std::string targetForm);
        class NotExistingForm : public std::exception {
               public:
                    const char* what() const throw();
        };
};

#endif