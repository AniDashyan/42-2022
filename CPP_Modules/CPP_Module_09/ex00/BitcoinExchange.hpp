#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <fstream>

const int MIN_YEAR = 2009;
const int MAX_YEAR = 2022;

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
        bool isValidValue(std::string line);
        void read_data_file();
        bool isLeapYear(int year);
    private:
        std::map<std::string, double> m_map;
};

#endif