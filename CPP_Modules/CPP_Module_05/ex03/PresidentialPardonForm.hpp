#ifndef PRESIDENTAL_PARDON_FORM_HPP
#define PRESIDENTAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;
    private:
        std::string m_target;
};

std::ostream& operator<<(std::ostream &stream, const PresidentialPardonForm& other);

#endif