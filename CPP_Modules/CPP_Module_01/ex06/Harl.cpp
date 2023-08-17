#include "Harl.hpp"

Harl::Harl() {
    std::cout << "Hey there👋. I'm Harl, and if there's one thing I'm absolutely world-class at, it's complaining! 🏆😅" << std::endl;
}

void Harl::debug() {
    std::cout << "🔍🐞 DEBUG:\n";
    std::cout << "I love having extra bacon 7XL-double-cheese-triple-pickle-specialketchup burger. I really do! 🍔🥓🧀🍅" << std::endl;
}

void Harl::info(void) {
    std::cout << "📚 INFO:\n";
    std::cout << "😱🥓 I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!  😤🍔" << std::endl;
}

void Harl::warning() {
    std::cout << "⚠️ WARNING:\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month" << std::endl;
}

void Harl::error() {
    std::cout << "🚫 ERROR:\n";
    std::cout << "😡👔 This is unacceptable! I want to speak to the manager now. 🗣️🚨" << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    complaint_ptr complaints[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i].compare(level) == 0)
        {
            (this->*(complaints[i]))();
            break;
        }
    }
}

Harl::~Harl() {
    std::cout << "Bye bye, but don't worry, I'm not going to complain about it... much! 👋🤪" << std::endl;
}