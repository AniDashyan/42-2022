#include "FileReplace.hpp"

FileReplace::FileReplace(std::string filename, std::string s1, std::string s2) : m_filename(filename), m_s1(s1), m_s2(s2) {
	if (m_s1.empty() || m_s2.empty())
		throw std::invalid_argument("❌ Error: Empty String ❌");
	try {
        infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        infile.open(filename);
    } catch (std::ifstream::failure &e) {
        std::cout << "❌ Error: Can't open the file ❌\n";
        throw; // Rethrow the exception to halt the constructor execution
    }
}

void FileReplace::replace() {
 	std::string out_filename = m_filename + ".replace";
	std::ofstream outfile(out_filename);
	if (!outfile.is_open() || !outfile.good())
	{
		std::cout << "❌ Error: Can't open the outfile ❌\n";
		return ;
	}
	std::string line; // reading file line by line
	int count = 0; // count of the found m_s1;
	infile.seekg(0, std::ios::end);
	int length = infile.tellg();
	if (length == 0)
	{
		std::cout << "❌ Error: Empty file ❌\n";
		return ;
	}
	infile.seekg(0, std::ios::beg);
	while (!infile.eof())
	{
		// reading from infile line by line until meeting new line "\n" in this case hitting ENTER
		getline(infile, line);
		int pos = 0;  // starting position to search
		std::string newLine;
    	while (pos < line.length()) {
			int foundPos = line.find(m_s1, pos); // find m_s1 in line starting from pos and assigning it to foundPos
			if (foundPos == std::string::npos) // Doesn't find m_s1
			{
				newLine.append(line.substr(pos));
				break;
			}
			else
			{
				count++;
        		newLine.append(line.substr(pos, foundPos - pos));
				newLine.append(m_s2);
				pos += foundPos + m_s1.length();
			}
    	}
		outfile << newLine << "\n";
	}	

	infile.close();
	outfile.close();
	if (count != 0)
		std::cout << "Replacement completed. Check '" << out_filename << "' for results." << std::endl;
	else
		std::cout << "String not found\n";
}

FileReplace::~FileReplace() {
	if (infile.is_open())
		infile.close();
}