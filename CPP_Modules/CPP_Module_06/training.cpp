#include <iostream>

// int main()
// {
//     // C style cast
//     float a = 2.0;
//     int b = 2;
//     int c = 3;

//     int d = a + b; // -> 2.0 + 2.0 = 4.0 -> 4
//     float e = c/b; // -> 3/2 = 1.5 -> 1
//     float f = (float)c/b; // -> 3/2 = 1.5 this way it's more precise

//     std::cout << "d= " << d << std::endl;
//     std::cout << "e= " << e << std::endl;
//     std::cout << "f= " << f << std::endl;

//     return (0);
// }

// static_cast
// int main()
// {
//     char c;

//     int* p1 = (int*)(&c); // -< allowed
//     // Prevent dangerous casts -> more restrictive than implicit cast
//     *p1 = 3;
//     int* p2 = static_cast<int *>(&c); // Compile-time ERROR
//     return (0);
// }

//
/* #include <string>

class A {
    private:
        int x;
    public:
        A(int i) : x(i) {
            std::cout << "Conversion Ctr" << std::endl;
        }

        operator std::string() {
            std::cout << "Conversion Operator" << std::endl;
            return std::to_string(x);
        }
};
int main() {
    A aobj(7);
    std::string s1 = aobj;
    aobj = 10;

    std::string s2 = static_cast<std::string>(aobj);
    aobj = static_cast<A>(50);
    return (0);
} */

/* class CDummy {
    float i;
    float j;
};

class CAddition {
    private:
        int x;
        int y;
    public:
        CAddition(int a, int b) : x(a), y(b) {}
        int result() {return (x + y);}
}; */

// The program decalres a pointer to CAddition, but then it assigns to it a reference to an object of another incompatible type using explicit type-casting (line 78)
/* int main()
{
    CDummy d;
    CAddition* padd;
    // Traditional explicit type-casting allows to convert any pointer into any other pointer type, independently of the types they point to. 
    padd = (CAddition*)&d;
    // The subsequent call to member function result() will produce either a run-time error or an unexpected result. 
    std::cout << padd->result() << std::endl;
    return (0); 
} */

