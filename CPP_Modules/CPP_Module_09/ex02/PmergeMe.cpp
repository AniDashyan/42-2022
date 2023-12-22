#include "PmergeMe.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <pair>

PMergeMe::PMergeMe() {

}

PMergeMe::PMergeMe(const PMergeMe& other) : m_vec(other.m_vec), m_list(other.m_list) {

}

PMergeMe& PMergeMe::operator=(const PMergeMe& other) {
    if (this != &other) {
        this->m_vec = other.m_vec;
        this->m_list = other.m_list;
    }
    return (*this);
}

PMergeMe::~PMergeMe() {

}

void PMergeMe::parsing(char** argv) {
    int i = 1;
    int value;
    while (argv[i] != NULL) {
        std::string str(argv[i]);
        if (str.empty())
            throw std::invalid_argument("Error: Arguments must not be empty!");

        if (str.find_first_not_of("0123456789") == std::string::npos) {
            value = atoi(str.c_str());
            if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
                throw std::out_of_range("Error: Numbers have to be in the range of int!");
            else if (value <= 0)
                throw std::runtime_error("Error: Numbers must be positive!");
            else {
                this->m_vec.push_back(value);
                this->m_list.push_back(value);
            }
        }
        else
            throw std::invalid_argument("Error: Invalid arguments");
        i++;
    }
    std::cout << "Vector: " << std::endl;
    for (size_t i = 0; i < this->m_vec.size(); i++)
        std::cout << "vec[" << i << "] = " << this->m_vec[i] << std::endl;

    std::cout << "List: " << std::endl;
    std::list<int>::iterator it = this->m_list.begin();
    int j = 0;
    for (; it != this->m_list.end(); it++)
        std::cout << "list[" << j++ << "] = " << *it << std::endl; 
}

void PMergeMe::FordJohnsonVector(std::vector<int> vec) {
    std::vector<std::pair<int, int> > new_vec;
    std::vector<int>::iterator it;
    for (it = this->m_vec.begin(); it != this->m_vec.end(); it+= 2)
    {
           
    }
}