#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

Span::Span() : m_N(0) {
    this->m_vector.reserve(0);
    // std::cout << "Default Constructor of Span Called" << std::endl;
}

Span::Span(unsigned int N) : m_N(N) {
    this->m_vector.reserve(N);
    // std::cout << "Parameter Constructor of Span Called" << std::endl;
}

Span::Span(const Span& other) : m_N(other.m_N), m_vector(other.m_vector) {
    // std::cout << "Copy Constructor of Span Called" << std::endl;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->m_N = other.m_N;
        this->m_vector = other.m_vector;
    }
    // std::cout << "Copy Assignment Operator of Span Called" << std::endl;
    return (*this);
}

Span::~Span() {
    // std::cout << "Destructor of Span Called" << std::endl;
}

std::vector<int> Span::getVector() const {
    return (this->m_vector);
}

void Span::addNumber(int num) {
    if (this->m_vector.size() >= this->m_N)
        throw std::out_of_range("Error: Maximum capacity reached. Can't add more elements!");

    this->m_vector.push_back(num);
}

int Span::shortestSpan() {
    if (this->m_vector.size() < 2)
        throw std::invalid_argument("Error: Vector is empty");

    std::sort(this->m_vector.begin(), this->m_vector.end());
    std::vector<int>result(this->m_vector.size());
    std::adjacent_difference(this->m_vector.begin(), this->m_vector.end(), result.begin());
    
    return (*std::min_element(result.begin() + 1, result.end()));
}

int Span::longestSpan() {
    if (this->m_vector.size() < 2)
        throw std::invalid_argument("Error: Vector is empty");

    return (*std::max_element(this->m_vector.begin(), this->m_vector.end()) - *std::min_element(this->m_vector.begin(), this->m_vector.end()));
}