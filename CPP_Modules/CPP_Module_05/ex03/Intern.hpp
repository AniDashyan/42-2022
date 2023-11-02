#ifndef INTERN_HPP
#define INTERN_HPP

class Intern {
    Intern();
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string formName, std::string targetName);
};

std::ostream& operator<<(std::ostream &stream, const Intern& other);
#endif