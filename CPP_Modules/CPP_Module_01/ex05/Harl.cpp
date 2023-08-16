#include "Harl.cpp"

Harl::Harl() {
    std::cout << "Hey there👋. I'm Harl, and if there's one thing I'm absolutely world-class at, it's complaining! 🏆😅" << std::endl;
}

void Harl::debug() {
    std::cout << "🔍🐞 DEBUG:\n"
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do! 🍔🥓🧀🍅" << std::endl;
}

void Harl::info(void) {
    std::cout << "📚 INFO:\n"
    std::cout << "😱🥓 I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!  😤🍔" << std::endl;
}

void Harl::warning() {
    std::cout << "⚠️ WARNING:\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for
years whereas you started working here since last month" << std::endl;
}

void Harl::error() {
    std::cout << "🚫 ERROR\n";
    std::cout << "😡👔 This is unacceptable! I want to speak to the manager now. 🗣️🚨" << std::endl;
} 

Harl::~Harl() {
    std::cout << "Bye bye, but don't worry, I'm not going to complain about it... much! 👋🤪" << std::endl;
}