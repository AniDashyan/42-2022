#include "FileReplace.hpp"

FileReplace::FileReplace(std::string filename, std::string s1, std::string s2) : m_filename(filename), m_s1(s1), m_s2(s2) {
	try {
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        file.open(filename);
    } catch (std::ifstream::failure e) {
        std::cerr << "❌ Error: Can't open the infile ❌\n";
        throw; // Rethrow the exception to halt the constructor execution
    }
}

void FileReplace::replace() {
	std::ofstream out_replace(m_filename + ".replace");
	std::string ch;
	if (!out_replace.is_open())
	{
		std::cerr << "❌ Error: Can't open the outfile ❌\n";
		return ;
	}
	while (!file.eof())
	{
		getline(file, ch);
		out_replace << ch;
		std::cout << ch << "\n";
	}
	file.close();
}

FileReplace::~FileReplace() {
	if (file.is_open())
		file.close();
}