#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);
        // TODO: implement
        // template<typename Iterator>
        // typename std::iterator_traits<Iterator>::value_type
        void addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
            for (std::vector<int>::iterator it = begin; it != end; it++)
                addNumber(*it);
        }
        int shortestSpan();
        int longestSpan();

        std::vector<int> getVector() const;
    private:
        unsigned int m_N;
        std::vector<int> m_vector;
};

#endif