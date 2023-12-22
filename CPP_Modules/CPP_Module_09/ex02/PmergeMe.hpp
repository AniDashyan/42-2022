#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <vector>
#include <list>

class PMergeMe {
    public:
        PMergeMe();
        PMergeMe(const PMergeMe& other);
        PMergeMe& operator=(const PMergeMe& other);
        ~PMergeMe();
    // private:
        void parsing(char** argv);
        void FordJohnsonVector();
        void FordJohnsonList();
        void sortPairs(std::vector<std::pair<int, int> > &pairs);
    private:
        std::vector<int> m_vec;
        std::list<int> m_list;
};

#endif