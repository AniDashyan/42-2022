#include "Base.hpp"
#include <iostream>


int main(void)
{
    Base *b = generate();
    identify(b);
    identify(*b);
    return (0);
}