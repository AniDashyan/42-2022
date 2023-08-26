// #pragma once
#ifndef FILE_REPLACE_HPP
#define FILE_REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class FileReplace {
	private:
		std::ifstream file;
		const std::string m_filename;
		const std::string m_s1;
		const std::string m_s2;
	public:
		FileReplace(std::string filename, std::string s1, std::string s2);
		void replace();
		~FileReplace();
};

#endif