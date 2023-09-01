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
	infile.seekg(0, std::ios::end);
	int length = infile.tellg();
	if (length == 0)
	{
		std::cout << "❌ Error: Empty file ❌\n";
		return ;
	}
	infile.seekg(0, std::ios::beg);
	std::string line; // reading file line by line
	int count = 0; // count of the found m_s1;
	// std::cout << "count: " << count << std::endl;
	while (!infile.eof())
	{
		getline(infile, line);
		// std::cout << "line before: " << line << std::endl;
		// std::string newLine;
		int foundPos = line.find(m_s1); // finding m_s1 in line and assigning it to foundPos
		while (foundPos != std::string::npos) // checking until m_s1 is not found
		{
			count++;
			line.erase(foundPos, m_s1.length());
			// std::cout << "line after erase: " << line << std::endl;
			line.insert(foundPos, m_s2);
			// std::cout << "line after insert: " << line << std::endl;
			foundPos = line.find(m_s1, foundPos + m_s2.length());
		}
		outfile << line << "\n";
		// std::cout << "hello while\n";
	}
	// std::cout << "hello\n";
	infile.close();
	outfile.close();
	if (count != 0)
		std::cout << "Replacement completed. Check '" << out_filename << "' for results." << std::endl;
	else
		std::cout << m_s1 << " not found in '" << m_filename << "'." << std::endl;
}

FileReplace::~FileReplace() {
	if (infile.is_open())
		infile.close();
}