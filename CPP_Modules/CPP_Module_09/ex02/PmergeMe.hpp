#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        static bool parsing(std::vector<std::string> args);
    private:
        std::vector<int> m_vec;
        std::deque<int> m_deq;
};

#endif