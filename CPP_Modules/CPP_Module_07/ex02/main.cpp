#include "Array.hpp"
#include <iostream>

int main(void) {
    try
    {
        // Default Constructor
        Array<float> a;
        std::cout << "a size= " << a.size() << std::endl;
        // std::cout << a[2] << std::endl; 

        // Parameter Constructor
        Array<int> arr(10);
        std::cout << "size= " << arr.size() << std::endl;
        Array<int> arr_1(50);
        std::cout << "size_1= " << arr_1.size() << std::endl;

        // Copy Constructor
        Array<int> arr2(arr_1);
        std::cout << "copy size=" << arr2.size() << std::endl;

        // Copy Assignment Operator
        arr = arr_1;
        std::cout << "size= " << arr.size() << std::endl;
        std::cout << "size_1= " << arr_1.size() << std::endl;
    
        arr_1 = arr;
        std::cout << "arr[i]= " << arr_1[17] << std::endl;


        std::cout << "sizeof= "<< arr_1.size() << std::endl;
        for (int i = 0; i < 5; ++i)
        {
            std::cout << "arr[" << i << "]=" << arr_1[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}