#include "FileReplace.hpp"

int main(int argc, char **argv) {
    if (argc == 4) {
        try {
            FileReplace file_replace(argv[1], argv[2], argv[3]);
            file_replace.replace();
        } catch (...) {}
    } 
	else
        std::cerr << "❌ Error: Bad arguments ❌" << std::endl;
    return 0;
}