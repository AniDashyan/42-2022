#include "Span.hpp"

Span::Span() : m_N(0) {

}

Span::Span(unsigned int N) : m_N(N) {
    this->m_vec.reserve(N);
}

Span::Span(const Span& other) : m_N(other.m_N) {
}

Span& Span::operator=(const Span& other) {
}

Span::~Span() {

}

void Span::addNumber(int num) {
    if (this->m_vec.size() > this->m_vec.capacity())
        throw std::out_of_range("Error: Maximum capacity reached. Can't add more elements!");

    this->m_vec.push_back(num);
}

int Span::shortestSpan() const {

}

int Span::longestSpan() const {

}