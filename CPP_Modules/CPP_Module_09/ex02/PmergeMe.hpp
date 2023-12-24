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

        void parsing(char** argv);
        void FordJohnsonVector();
        void FordJohnsonDeque();
        void printVector(const std::vector<int>& vec);
        void printDeque(const std::deque<int>& deq);
        double get_time(void);

        std::vector<int> getVector() const;
        std::deque<int> getDeque() const;
        size_t getVectorSize() const;
        size_t getDequeSize() const;
    private:
        void swapPairElementsVector(std::vector<std::pair<int, int> > &pairs);
        void swapPairElementsDeque(std::deque<std::pair<int, int> > &pairs);
    private:
        std::vector<int> m_vec;
        std::deque<int> m_deq;
};

bool sortPairs(std::pair<int, int>& a, std::pair<int, int>& b);

#endif