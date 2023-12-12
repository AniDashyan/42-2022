#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            std::stack<T>::operator=(other);
        }
        ~MutantStack() {}

        iterator begin() {
            return (this->c.begin());
        }

        iterator end() {
            return (this->c.end());
        }
};

#endif