#include "FileReplace.hpp"

// FileReplace::FileReplace() {

// }

FileReplace::FileReplace(std::string filename) {
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

void replace(std::ifstream &file, std::string s1, std::string s2) {

}

FileReplace::~FileReplace() {
	if (file.is_open())
		file.close();
}