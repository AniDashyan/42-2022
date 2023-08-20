#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        typedef void (Harl::*complaint_ptr)(void);
        Harl();
        void complain(std::string level);
        ~Harl();
};
#endif