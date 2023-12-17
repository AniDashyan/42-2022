#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <cstdlib>

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
        if (line != "date,exchange_rate") {
            if ((pos = line.find(",")) != std::string::npos) {
                date = line.substr(0, pos);
                this->m_map[date] = std::strtod(line.substr(pos + 1).c_str(), NULL);
            }
            else
                throw std::runtime_error("Error: 'data.csv' file is in wrong format");
            }
    }

    // std::map<std::string, double>::iterator it;
    // for (it = this->m_map.begin(); it != this->m_map.end(); it++)
    // {
    //     std::cout << it->first << " "  << it->second << std::endl;
    // }   
    data.close();
}

void BitcoinExchange::read_input_file(std::string file) {
    std::ifstream data(file);
    std::string line;
    std::string date;
    double value;
    size_t pos;

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
        // std::cout << "line: " << line << std::endl;
        if (line.empty()) {
            throw std::runtime_error("Error: Empty line =>");
        }

        // TODO: check format of line "date | value"
        // if (std::count(line.begin(), line.end(), '|') != 1)
        //     std::cout << "Error: bad input rgergerg=> " << std::endl;
        
        if ((pos = line.find("|")) != std::string::npos) 
        {
            if (isValidDate(clearSpaces(line.substr(0, pos))))
            {
                date = clearSpaces(line.substr(0, pos));
            } 
            // else
            //    std::cout << "Error: bad input => " << date << std::endl;

            // std::cout << clearSpaces(line.substr(pos + 1)) << std::endl;
            if (isValidValue(clearSpaces(line.substr(pos + 1)))) 
            {
                value = std::strtod((clearSpaces(line.substr(pos + 1))).c_str(), NULL);
                std::map<std::string, double>::iterator it = this->m_map.lower_bound(date);
                if (it != this->m_map.end())
                {
                    double money = it->second * value;
                    std::cout << date << " => " << value << " = " << money << std::endl;
                }
                else 
                    std::cout << "Error: Not found" << std::endl;
            }
            // else
            //    std::cout << "Error: Invalid value => " << date << std::endl;
        }
        else
            std::cout << "Error: bad input => " << line <<  std::endl;
    }
}

// Think of a name
void BitcoinExchange::function(std::string file) {
    try {
        read_data_file();
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
        if ((i == 4 || i == 7)) {
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
        std::istringstream iss(splitted_date);
        if (index == 0) {
            iss >> year;
            if (iss.fail() || iss.bad() || iss.get() != EOF)
                return false;

            if (year > MAX_YEAR || year < MIN_YEAR) { // harcnel Vahanin
                return (false);
            }
        }
        else if (index == 1) {
            iss >> month;
            if (iss.fail() || iss.bad() || iss.get() != EOF)
                return (false);
            
            if (month < 1 || month > 12) {
                return (false);
            }
        }
        else if (index == 2){
            iss >> day;
            if (iss.fail() || iss.bad() || iss.get() != EOF)
                return (false);

            if (day < 1 || day > 31)
            {
                return (false);
            }
            else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) { // months with 30 days
                return (false);
            }
            else if (month == 2 && isLeapYear(year) && day > 29) {
                return (false);
            }
            else if (month == 2 && !isLeapYear(year) && day > 28) {
                return (false);
            }
        }
        index++;
    }
    return (true);
}

bool BitcoinExchange::isValidValue(std::string line) {
    char* endPtr; 
    double value = std::strtod(line.c_str(), &endPtr);
    std::string end(endPtr);
    if (!end.empty())
    {
        std::cout << "Error: Inavlid value => " << line << std::endl;
        return (false);
    }
    else if (value < 0 || value > 1000) {
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return (false);
        }
        else if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            return (false);
        }
    }
    return (true);
}

std::string BitcoinExchange::clearSpaces(std::string line) {
    line.erase(0, line.find_first_not_of(" "));
    line.erase(line.find_last_not_of(" ") + 1, line.length());
    return (line);
}

bool BitcoinExchange::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}