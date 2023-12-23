#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <vector>
#include <deque>

class PMergeMe {
    public:
        PMergeMe();
        PMergeMe(const PMergeMe& other);
        PMergeMe& operator=(const PMergeMe& other);
        ~PMergeMe();

        void parsingVector(char** argv);
        void parsingDeque(char** argv);
        void FordJohnsonVector(std::vector<int>& vec);
        void FordJohnsonDeque(std::deque<int>& deq);
        void printVector(std::vector<int> vec);
        void printDeque(std::deque<int> deq);
        double get_time(void);

        std::vector<int> getVector() const;
        std::deque<int> getDeque() const;
        size_t getVectorSize() const;
        size_t getDequeSize() const;
    private:
        void sortPairs(std::vector<std::pair<int, int> > &pairs);
    private:
        std::vector<int> m_vec;
        std::deque<int> m_deq;
};

#endif