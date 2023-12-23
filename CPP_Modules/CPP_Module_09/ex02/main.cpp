#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>


int main(int argc, char** argv) {
    if (argc > 2) {
        try {
            PMergeMe pmg;
            std::vector<int> vec;
            std::deque<int> deq;

            pmg.parsingVector(argv);
            vec = pmg.getVector();

            pmg.parsingDeque(argv);
            deq = pmg.getDeque();

            std::cout << "Before: ";
            pmg.printVector(vec);
            std::cout << std::endl;

            double start_vec = pmg.get_time();
            pmg.FordJohnsonVector(vec);
            double end_vec = pmg.get_time();
            
            double start_deq = pmg.get_time();
            pmg.FordJohnsonDeque(deq);
            double end_deq = pmg.get_time();

            std::cout << "After: ";
            pmg.printVector(vec);
            std::cout << std::endl;
            
            std::cout << "Time to process a range of " << pmg.getVectorSize() << " elements with std::vector : " << (end_vec - start_vec) << " us" << std::endl;
            std::cout << "Time to process a range of " << pmg.getDequeSize() << " elements with std::deque : " << (end_deq - start_deq) << " us" << std::endl;

            std::cout << std::fixed <<  "\nstart_vec: " << start_vec << " end_vec: " << end_vec << std::endl;
            std::cout << std::fixed << std::setprecision(15) <<  "\nstart_deq: " << start_deq << " end_deq: " << end_deq << std::endl;
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error: Arguments must be more than 1" << std::endl;
    return (0);
}