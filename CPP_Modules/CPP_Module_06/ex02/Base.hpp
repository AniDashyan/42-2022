#ifndef BASE_HPP
#define BASE_HPP

class Base {
    public:
        virtual ~Base();
};

class A : Base {

};

class B : Base {

};

class C : Base {

};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif