#include "Harl.hpp"

int harl_filter(char *level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR "};
    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            return (i);
        return (-1);
}

void harl_switch(char *level, Harl &harl) {
    switch (harl_filter(level)) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
        default:
            std::cout << "[😠 Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

int main(int argc, char **argv) {
    Harl harl;
    if (argc == 2)
        harl_switch(argv[1], harl);
    else
        std::cout << "[😠 Probably complaining about insignificant problems 😠]" << std::endl;
    return (0);
}