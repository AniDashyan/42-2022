#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe& other) {
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    // if (this != &other)
    // {

    // }
    (void)other;
    return (*this);
}

PmergeMe::~PmergeMe() {
    
}

bool PmergeMe::parsing(std::vector<std::string> args) {
    
}