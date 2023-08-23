#include "FileReplace.hpp"

// FileReplace::FileReplace() {

// }

FileReplace::FileReplace(std::string filename) : _filename(filename) {
	file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  	try {
    	file.open(filename);
  	}
  	catch (std::ifstream::failure e) {
    	std::cerr << "❌ Error: Can't open the file ❌\n";
  	}
}

void FileReplace::setS1(std::string s1) {
	this->_s1 = s1;
}

void FileReplace::setS2(std::string s2) {
	this->_s2 = s2;
}

std::string FileReplace::getS1() {
	return this->_s1;
}

std::string FileReplace::getS2() {
	return this->_s2;
}

void FileReplace::replace() {
	std::ofstream out_replace(_filename + ".replace");
	std::string ch;
	if (!out_replace.is_open())
	{
		std::cerr << "❌ Error: Can't open the file ❌\n";
		return ;
	}
	while (!file.eof())
	{
		getline(file, ch);
		out_replace << ch;
		std::cout << ch;
	}
	file.close();

	while (!out_replace.eof())
	{
		
		std::cout << ch;
	}
}

FileReplace::~FileReplace() {
	if (file.is_open())
		file.close();
}