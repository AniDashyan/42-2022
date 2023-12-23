#include "PmergeMe.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <sys/time.h>

PMergeMe::PMergeMe() {

}

PMergeMe::PMergeMe(const PMergeMe& other) : m_vec(other.m_vec), m_deq(other.m_deq) {

}

PMergeMe& PMergeMe::operator=(const PMergeMe& other) {
    if (this != &other) {
        this->m_vec = other.m_vec;
        this->m_deq = other.m_deq;
    }
    return (*this);
}

PMergeMe::~PMergeMe() {

}

void PMergeMe::parsingVector(char** argv) {
    int i = 1;
    int value;
    while (argv[i] != NULL) {
        std::string str(argv[i]);
        if (str.empty())
            throw std::invalid_argument("Error: Arguments must not be empty!");

        if (str.find_first_not_of("0123456789") == std::string::npos) {
            value = atoi(str.c_str());
            if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
                throw std::out_of_range("Error: Numbers have to be in the range of int!");
            else if (value <= 0)
                throw std::runtime_error("Error: Numbers must be positive!");
            else {
                this->m_vec.push_back(value);
            }
        }
        else
            throw std::invalid_argument("Error: Invalid arguments");
        i++;
    }
}

void PMergeMe::parsingDeque(char** argv) {
    int i = 1;
    int value;
    while (argv[i] != NULL) {
        std::string str(argv[i]);
        if (str.empty())
            throw std::invalid_argument("Error: Arguments must not be empty!");

        if (str.find_first_not_of("0123456789") == std::string::npos) {
            value = atoi(str.c_str());
            if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
                throw std::out_of_range("Error: Numbers have to be in the range of int!");
            else if (value <= 0)
                throw std::runtime_error("Error: Numbers must be positive!");
            else {
                this->m_deq.push_back(value);
            }
        }
        else
            throw std::invalid_argument("Error: Invalid arguments");
        i++;
    }
}

void PMergeMe::sortPairs(std::vector<std::pair<int, int> > &pairs) {
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

void PMergeMe::FordJohnsonVector(std::vector<int>& vec) {
    std::vector<std::pair<int, int> > new_vec;
    size_t end = vec.size();
    bool unpaired = false;
    for (size_t i = 0; i < end; i += 2) {
        if (end % 2 == 1 && i == end - 1)
        {
            unpaired = true;
            break;
        }
        new_vec.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    sortPairs(new_vec);

    std::vector<int> largests;
    std::vector<int> smallests;

    for (size_t i = 0; i < new_vec.size(); i++)
    {
        largests.push_back(new_vec[i].first);
        smallests.push_back(new_vec[i].second);
    }

    if (unpaired == true)
        smallests.push_back(vec[end - 1]);

    std::sort(largests.begin(), largests.end());

    largests.insert(largests.begin(), smallests[0]);
    int Jn_2 = 1;
    int Jn_1 = 1;
    int Jn = Jn_1 + 2 * Jn_1;
    while (Jn - 1 < static_cast<int>(smallests.size()))
    {
        for (int j = Jn - 2; j >= Jn_1; --j)
        {
            std::vector<int>::iterator it = std::upper_bound(largests.begin(), largests.end(), smallests[j]);
            largests.insert(it, smallests[j]);
        }
        Jn_2 = Jn_1;
        Jn_1 = Jn;
        Jn = Jn_1 + 2 * Jn_2;
    }

    for (int j = smallests.size() - 1; j > Jn_1 - 1; --j)
    {
        std::vector<int>::iterator it = std::upper_bound(largests.begin(), largests.end(), smallests[j]);
        largests.insert(it, smallests[j]);
    }
    vec = largests;
}

void PMergeMe::FordJohnsonDeque(std::deque<int>& deq) {
    std::vector<std::pair<int, int> > new_vec;
    size_t end = deq.size();
    bool unpaired = false;
    for (size_t i = 0; i < end; i += 2) {
        if (end % 2 == 1 && i == end - 1)
        {
            unpaired = true;
            break;
        }
        new_vec.push_back(std::make_pair(deq[i], deq[i + 1]));
    }
    sortPairs(new_vec);

    std::deque<int> largests;
    std::deque<int> smallests;

    for (size_t i = 0; i < new_vec.size(); i++)
    {
        largests.push_back(new_vec[i].first);
        smallests.push_back(new_vec[i].second);
    }

    if (unpaired == true)
        smallests.push_back(deq[end - 1]);

    std::sort(largests.begin(), largests.end());

    largests.insert(largests.begin(), smallests[0]);
    int Jn_2 = 1;
    int Jn_1 = 1;
    int Jn = Jn_1 + 2 * Jn_1;
    while (Jn - 1 < static_cast<int>(smallests.size()))
    {
        for (int j = Jn - 2; j >= Jn_1 - 1; --j)
        {
            std::deque<int>::iterator it = std::upper_bound(largests.begin(), largests.end(), smallests[j]);
            largests.insert(it, smallests[j]);
        }
        Jn_2 = Jn_1;
        Jn_1 = Jn;
        Jn = Jn_1 + 2 * Jn_2;
    }
    for (int j = smallests.size() - 1; j > Jn_1 - 1; --j)
    {
        std::deque<int>::iterator it = std::upper_bound(largests.begin(), largests.end(), smallests[j]);
        largests.insert(it, smallests[j]);
    }
    deq = largests;
}

std::vector<int> PMergeMe::getVector() const {
    return (this->m_vec);
}

std::deque<int> PMergeMe::getDeque() const {
    return (this->m_deq);
}

size_t PMergeMe::getVectorSize() const {
    return (this->m_vec.size());
}

size_t PMergeMe::getDequeSize() const {
    return (this->m_deq.size());
}

void PMergeMe::printVector(std::vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
}

void PMergeMe::printDeque(std::deque<int> deq) {
    for (size_t i = 0; i < deq.size(); i++)
        std::cout << deq[i] << " ";
}

double	PMergeMe::get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (static_cast<double>(tv.tv_usec) / 1000));
}