#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int main()
// {
//     Animal a;
//     a.makeSound();

//     Dog c;
//     c.makeSound();

//     // WrongAnimal w;
//     // w.makeSound();


//     // Dog d;
//     // d.makeSound();
    
//     // WrongCat wc;
//     // wc.makeSound();

//     return (0);
// }

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     return 0;
// }

int main()
{
    // Animal test;
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

    delete j;//should not create a leak
    delete j1;//should not create a leak
    delete i;

    delete i1;
    // system("leaks animal");
    // ...
    return (0);
}