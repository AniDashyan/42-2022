#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;


class B {
    private:
        int a;
    public:
        B() { std::cout << "Constructor of B is called\n";}
        ~B() {std::cout << "Destructor of B is called\n";}
};

class D : public B {};

int trouble() {
    return (true);
}

// This function has the reference to base class which points to derived class in main
void f(B& throw_if_trouble) {
    if (trouble())
    // throw is not a virtual function
    // type of throw is determined at compile time 
    // Whatever the type of throw_if_trouble has that type of exception is thrown. It's like a copy
    throw throw_if_trouble; // If we are copying a base type out of derived type we get a slice
}


/* This program cathes the (...) because */
// int main() {
//     D status;
//     try {
//         /* f() has base class reference as argument but is called with an 
//         argument of derived class and it works because base reference points to derived class 
//         */
//         f(status);
//     }
//     catch(D& e) {
//         std::cout << "It's a D\n";
//     }
//     /* When executing a program this one fires because exception throw is static.
//     Exception type is determined at compile time not at runtime */
//     catch(...) {
//         std::cout << "Well that's weird\n";
//     }
// }

// Exceptions can be thrown polymorphically by using virtual functions
/* In order to do that we make the throw itself a vritual function */
class Ba {
    public:
        virtual void raise() {
            throw *this; // This throws the base class exception
        }
};

class De : public Ba {
    virtual void raise() {
        throw *this; // This throws the derived class exception
        // and if the reference is really a reference to D then D will actually be thrown.
        // Becuase polymorphism occurs not at the point of throw, but at the where we decide which of these functions should be called 
    }
};

int trouble() {
    return (true);
}

void f1(Ba& throw_if_trouble) {
    if (trouble())
        throw_if_trouble.raise();
}

// Q: Can exceptiom handler throw itself throw?
// A: YES

// You can throw without arguments
// example
/* try {...}
catch (...) {
    std::cout << "Oops! " << std::endl;
    throw; // This throws the current exception.In other words whatever we were handling gets rezone and continues to propagate
} */

// ----------------------------- RE-THROWING EXCEPTIONS ----------------------------
/* Exception Dispatcher */
// Example

void dispatcher() {
    // after rethrowing in catch dispatcher handles the exception here
    /* try {
        throw;
    }
    catch(exception1& e) {
        std::cout << "handle exception1\n";
    }
     catch(exception2& e) {
        std::cout << "handle exception2\n";
    }
}

int main() {
    try { something_dangerous(); }
    catch(...) {dispatcher();} //dispatcher gets called in the catch block and only thing it does it rethrows the current exception 
    return 0;
} */

// -------------------------------------------------------------------------------------


// --------------- EXCEPTION SAFETY IS HARD ----------------
// Example
class Widget {
    public:
        Widget() { std::cout << "Constructor of widget" << std::endl;}
        ~Widget() { std::cout << "Destructor of widget" << std::endl;}
};

class Log {
    public:
        void open() {std::cout << "Open" << std::endl;}
        void record(Widget &w) {std::cout << "Record" << std::endl;}
        void close() {std::cout << "Close" << std::endl;}
};

// Q: What could possibly go wrong here?
// A: EVERYTHING.
/* Widget* make_widget(Log* l) {
    // open can throw
    l->open(); // if this line throws nothing will happen, no harm

    // new keyword including construction can throw
    Widget *w = new Widget(); // If this line throws function exits log remains open

    // record() can throw
    l->record(); // If this line throws we don't return the pointer but we have allocated it and now there is no way to get to the Widget anymore. Therefore widget leaks and log remains open. But a bigger problem other than memoery leakage is 
    // Q: what will happen if conatins a lock which should be unlocked later?
    // A: In that case we also leaked a lock


    l->close();
    return w;
} */

// The example above shows why the use of exceptions are bad
// Now the same exmaple using return codes
/* Widget* make_widget(Log* l) {
    
    l->open(); // In case of error return code is ignored just like printf()

    Widget *w = new Widget(); // memory allocation can fail, return NULL
    // probably would never happen
    // - la-la-la, I can't hear you...

    l->record(); // can fail, return error code
    // - la-la-la, I can't hear you...

    l->close();
    return w;
}

// Write the exmaple code actually using the error codes
Widget* make_widget(Log* l) {
    
    if (l->open() < 0)
        return NULL;

    Widget *w = new Widget();
    if (!w)
        return NULL;

    if (l->record(w) < 0)
        return NULL;

    if (l->close() < 0)
        return NULL;
    return w;
} */

// Hnadle errors not