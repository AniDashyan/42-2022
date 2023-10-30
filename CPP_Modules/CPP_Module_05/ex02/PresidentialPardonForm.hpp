#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

classPresidentialPardonForm : public AForm {

    public:
       PresidentialPardonForm();
       PresidentialPardonForm(const std::string& target);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
        
    private:
        std::string m_target();
}

#endif