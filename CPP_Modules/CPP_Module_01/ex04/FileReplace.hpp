// #pragma once
#ifndef FILE_REPLACE_HPP
#define FILE_REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class FileReplace {
	private:
		std::ifstream file;
		std::string _s1;
		std::string _s2;
	public:
		// FileReplace();
		FileReplace(std::string filename);
		void replace(std::ifstream &file, std::string s1, std::string s2);
		void setS1(std::string s1);
		void setS2(std::string s2);
		std::string getS1();
		std::string getS2();

		~FileReplace();
};

#endif