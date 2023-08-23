#include "FileReplace.hpp"

int main(int argc, char **argv) {
	if (argc == 4)
	{
		// std::string filename = argv[1];
		FileReplace file_replace(argv[1]);
		file_replace.setS1(argv[2]);
		file_replace.setS2(argv[3]);
		file_replace.replace();
	}
	else
		std::cout << "❌ Error: Bad arguments ❌" << std::endl;
	return (0);
}