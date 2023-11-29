#include "Serializer.hpp"
#include <iostream>

int main() {
    Data* ptr = new Data;
    uintptr_t raw;

    ptr->member1 = "Hello";
    ptr->member2 = "World!";

    raw = Serializer::serialize(ptr);
    std::cout << "raw: " << &raw << std::endl;
    std::cout << "raw->member1: " << ptr->member1 << std::endl;
    std::cout << "raw->member2 " << ptr->member2 << std::endl;
    ptr = Serializer::deserialize(raw);
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "ptr->member1: " << ptr->member1 << std::endl;
    std::cout << "ptr->member2: "  << ptr->member2 << std::endl;
    return (0);
}