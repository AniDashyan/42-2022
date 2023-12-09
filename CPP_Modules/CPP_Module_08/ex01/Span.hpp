#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);
        template <typename Iterator>
        void addManyNumbers(Iterator begin, Iterator end) {
            if (this->m_vector.size() + std::distance(begin, end) > this->m_N)
                throw std::length_error("Error: Can't add more elements. Capacity overflow");

            this->m_vector.insert(this->m_vector.end(), begin, end);
        }

        int shortestSpan();
        int longestSpan();

        std::vector<int> getVector() const;
    private:
        unsigned int m_N;
        std::vector<int> m_vector;
        Span();
};

#endif