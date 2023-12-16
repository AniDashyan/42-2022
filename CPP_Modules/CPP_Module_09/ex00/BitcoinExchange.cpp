#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <sstream>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : m_map(other.m_map) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->m_map = other.m_map;

    return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::read_data_file() {
    std::ifstream data;

    std::string line;
    std::string date;
    size_t pos;

    data.open("data.csv");
    if (!data.is_open())
        throw std::runtime_error("Error: Can't open 'data.csv' file");

    while (!data.eof()) {
        getline(data, line);
        if (line.empty())
            continue;
        if ((pos = line.find(",")) != std::string::npos) {
            date = line.substr(0, pos);
            this->m_map[date] = std::strtod(line.substr(pos + 1).c_str(), NULL);
        }
        else
            throw std::runtime_error("Error: 'data.csv' file is in wrong format");
    }       
    data.close();
}

void BitcoinExchange::read_input_file(std::string file) {
    std::ifstream data(file);
    std::string line;
    std::string date;
    double value;

    // Check file validity
    if (file.empty())
        throw std::invalid_argument("Error: No filename provided");
    else if (file.compare("data.csv") == 0)
        throw std::runtime_error("Error: Invalid file");

    if (!data.is_open() || !data.good())
        throw std::runtime_error("Error: Can't open input file");

    // Check the first line
    getline(data, line);
    if (line != "date | value")
    {
        data.close();
        throw std::runtime_error("Error: Invalid file format");
    }
    
    while (!data.eof()) {
        getline(data, line);
        if (line.empty()) {
            std::cout << "Error: Empty line =>" << std::endl;
            return;
        }
        // TODO: check format of line "date | value"
        // TODO: cut the  `date` and `value` from `line`
        std::cout << line << std::endl;
    }
}

void BitcoinExchange::function(std::string file) {
    try {
        read_data_file();
        read_input_file(file);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

// bool BitcoinExchange::isValidDate(std::string line) {
//     if (line.length() != 10)
//         return (false);

//     // Check validity of dashes
//     for (size_t i = 0; i < line.size(); i++)
//     {
//         if (i == 4 || i == 7) {
//             if (line[i] != '-')
//                 return (false);
//         }
//         else {
//             if (!isdigit(line[i]))
//                 return (false);
//         }
//     }

//     std::istringstream ss(line.c_str());
//     std::string splitted_date;
//     int year, month, day;
//     // int index = 0;
//     while (getline(ss, splitted_date, '-')) {
//         std::istringstream(splitted_date) >> year;
//     }

//     // if (index != 3)
//     //     return (false);

//     return (true);
// }

bool BitcoinExchange::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}