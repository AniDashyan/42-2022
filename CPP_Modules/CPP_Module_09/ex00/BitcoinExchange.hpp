#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <fstream>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void function(std::string file);
    private:
        void read_input_file(std::string file);
        bool isValidDate(std::string line);
        int isValidValue(std::string line);
        void read_data_file();
        std::string clearSpaces(std::string line);
        bool isLeapYear(int year);
    private:
        std::map<std::string, double, std::greater<std::string> > m_map;
};

#endif