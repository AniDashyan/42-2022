#include "Cat.hpp"
#include "Dog.hpp"

// int main() {
//     Animal obj1("John");
//     obj1.makeSound();
//     // Animal obj2(obj);
//     // Animal obj3;

//     // obj3 = obj2;

//     Cat obj;
//     obj.makeSound();
//     // Cat obj2(obj);
//     // Cat obj3;

//     // obj3 = obj2;
//     Dog obj2;
//     obj2.makeSound();
//     // Dog obj2(obj);
//     return (0);
// }

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
return 0;
}