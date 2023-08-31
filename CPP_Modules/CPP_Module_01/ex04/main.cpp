#include "FileReplace.hpp"

int main(int argc, char **argv) {
    if (argc == 4) {
        try {
            FileReplace file_replace(argv[1], argv[2], argv[3]);
            file_replace.replace();
        } 
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
        catch (...) {}
    } 
	else
        std::cout << "❌ Error: Bad arguments ❌" << std::endl;
    return 0;
}