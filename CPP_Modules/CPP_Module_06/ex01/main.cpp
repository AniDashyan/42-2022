#include "Serializer.hpp"
#include <iostream>

int main() {
    Data* data = new Data;
    Data* ptr;
    uintptr_t raw;

    data->member1 = "Hello";
    data->member2 = "World!";

    raw = Serializer::serialize(data);
    // std::cout << "raw: " << raw << std::endl;
    std::cout << "raw->member1: " << data->member1 << std::endl;
    std::cout << "raw->member2 " << data->member2 << std::endl;
    ptr = Serializer::deserialize(raw);
    // std::cout << "ptr: " << ptr << std::endl;
    std::cout << "ptr->member1: " << ptr->member1 << std::endl;
    std::cout << "ptr->member2: "  << ptr->member2 << std::endl;
    return (0);
}