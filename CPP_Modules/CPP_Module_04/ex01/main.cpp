#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal* j = new Dog();
    Cat* i = new Cat();

    Cat* i1 = new Cat();
    *i = *i1;

    Dog* j1 = new Dog();

    *j = *j1;

    Animal *animals[10];
    for (int i = 0; i < 10; i++)
    {
        animals[i] = new Cat();
        i++;
        animals[i] = new Dog();
    }

    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }

    Dog basic;
    {
        Dog tmp = basic;
    }
    delete j;//should not create a leak
    delete j1;//should not create a leak
    delete i;

    delete i1;
    // system("leaks animal");
    // ...
    return (0);
}