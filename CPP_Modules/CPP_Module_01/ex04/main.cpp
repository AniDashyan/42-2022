#include "FileReplace.hpp"

int main(int argc, char **argv) {
	if (argc == 4)
	{
		std::string filename = argv[1];
		// std::string s1 = argv[1];
		// std::string s2 = argv[2];
		FileReplace file_replace(filename);
		file_replace.setS1(argv[2]);
		file_replace.setS2(argv[3]);
		std::cout << file_replace.getS1() << " ajajajja " << file_replace.getS2() << std::endl;
	}
	else
		std::cout << "❌ Error: Bad arguments ❌" << std::endl;
	return (0);
}

// class MyClass {
// private:
//     std::ifstream inputFile;

// public:
//     MyClass(const std::string& filename) {
//         inputFile.open(filename);
//         if (!inputFile.is_open()) {
//             std::cerr << "Error opening file: " << filename << std::endl;
//         }
//     }

//     void readAndPrint() {
//         std::string line;
//         while (std::getline(inputFile, line)) {
//             std::cout << line << std::endl;
//         }
//     }

//     ~MyClass() {
//         if (inputFile.is_open()) {
//             inputFile.close();
//         }
//     }
// };

// int main() {
//     MyClass myObject("main.cpp");
//     myObject.readAndPrint();

//     return 0;
// }
