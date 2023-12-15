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
    std::fstream data;

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
    std::string line;
    std::ifstream data(file);

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
        std::cout << line << "\n";
    }
}

void BitcoinExchange::function(std::string file) {
    try {
        read_data_file(); // TODO: Fix the function
        read_input_file(file);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

bool BitcoinExchange::isValidDate(std::string line) {
    if (line.length() != 10)
        return (false);

    // Check validity of dashes
    for (size_t i = 0; i < line.size(); i++)
    {
        if (i == 4 || i == 7) {
            if (line[i] != '-')
                return (false);
        }
        else {
            if (!isdigit(line[i]))
                return (false);
        }
    }

    std::istringstream ss(line.c_str());
    std::string splitted_date;
    int year, month, day;
    int index = 0;
    while (getline(ss, splitted_date, '-')) {
        if (index == 0)
        {
            std::istringstream(splitted_date) >> year;
            if (year > MAX_YEAR || year < MIN_YEAR)
                return (false);
        }
        else if (index == 1) {
            std::istringstream(splitted_date) >> month;
            if (month < 1 || month > 12)
                return (false);
        }
        else if (index == 2) {
            std::istringstream(splitted_date) >> day;
            if (day < 1 || day > 31)
                return (false);

            if ((month == 4 || month == 7 || month == 9 || month == 11) && day == 31) // months which have 30 days
                return (false);
            
            if(isLeapYear(year)) // leap year
            {
                if (month == 2 && day > 29)
                    return (false);
            }
            else if (month == 2 && day > 28)
                return (false);
        }
        index++;
    }

    if (index != 3)
        return (false);

    return (true);
}

bool BitcoinExchange::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}