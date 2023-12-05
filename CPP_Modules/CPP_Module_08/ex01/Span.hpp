#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
    private:
        unsigned int m_N;
        std::vector<int> m_vec;
};
#endif
