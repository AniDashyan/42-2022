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
            for (; begin != end; begin++)
                addNumber(*begin);
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