#include "Base.hpp"
#include <ctime>
#include <iostream>

Base::~Base() {}

Base *generate(void) {
    std::srand(time(NULL));
    switch (std::rand() % 3)
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
        default:
            return (NULL);
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Object Type: *A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Object Type: *B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Object Type: *C" << std::endl;
    else
        std::cout << "Object Type: Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Object Type: A" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Object Type: B" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Object Type: C" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
