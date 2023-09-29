#include <iostream>
#include <fstream>
#include <vector>
// Header file for handling exceptions
#include <exception>
#include <string>
// the header file from where invalid_argument and runtime_exception come from
#include <stdexcept>

// --- Throwing and Catching Exceptions ---

// void    readIntegerFile(const std::string& fileName, std::vector<int>& dest)
// {
//     std::ifstream istr;
//     int tmp;

//     // The most likely problem to occur in this function is for the file open to fail
//     istr.open(fileName.c_str());
//     if (istr.fail())  // If open fails throw is executed and the rest of the function is skipped
//     {
//         // Open failed: throw an exception;
//         /* throw is a keyword in C++, and is the only way to throw an exception. C++ provides a class named `exception`, decalred int <exception> header file. The std::exception() part of the throw means that we are constructing a new object of type exception to throw */
//         throw std::exception(); 
//     }

//     // Reading ints one by one and adding them to the vector
//     while (istr >> tmp)
//     {
//         dest.push_back(tmp);
//     }
// } 


// int main(int argc, char** argv)
// {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     // When throwing exception we must handle it too
//     /* Exception handling is a way to "try" a block of code, with another block of code designated to react to any problems that might occur. In this case "catch" reacts to any exception of the type exception what was within the try block by printing an error message and exiting. */
//     try {
//         readIntegerFile(fileName, myInts);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "Unable to open file '" << fileName << "'" << std::endl;
//         exit(1);
//     }
//     // try and catch are like glorified if/else

//     for (size_t i = 0; i < myInts.size(); i++)
//     {
//         std::cout << myInts[i] << " ";
//     }
//     std::cout << std::endl;
//     return (0);
// } 

// -----------------------------------------------------------

/* Although by default streams do not throw exceptions, you can tell the streams to throw exceptions for
error conditions by calling their exceptions() method. However, no less a luminary than Bjarne Stroustrup (who created C++) recommends against this approach. In The C++ Programming Language, third edition, he says “ . . . I prefer to deal with the stream state directly. What can be handled with local control structures within a function is rarely improved by the use of exceptions.” */

// ----------------------------------------------------

// --- Exception Types ---

// void    readIntegerFile(const std::string& fileName, std::vector<int>& dest)
// {
//     std::ifstream istr;
//     int tmp;

   
//     istr.open(fileName.c_str());
//     if (istr.fail()) 
//     {
//         // Open failed: throw an exception
//         // throw 5;  // itn type thrown
//         throw "Unable to open file "; // char* thrown 
//     }

//     // Reading ints one by one and adding them to the vector
//     while (istr >> tmp)
//     {
//         dest.push_back(tmp);
//     }
// } 

// int main(int argc, char** argv)
// {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     try {
//         readIntegerFile(fileName, myInts);
//     }
//     // catch (int e) {
//     //     std::cerr << "Unable to open file " << fileName << std::endl;
//     //     exit(1);
//     // }
//     catch (const char* e) {
//         std::cerr << e << fileName << std::endl;
//         exit(1);
//     }

//     for (size_t i = 0; i < myInts.size(); i++)
//     {
//         std::cout << myInts[i] << " ";
//     }
//     std::cout << std::endl;
//     return (0);
// } 

// ------------------------------------------------------------

/* However we should throw objects as exceptions for 2 reasons 
        1) Objects convey information by their class name
        2) Objects can store information, such as strings, that describe the exceptions
*/

// ------------------------------------------------------------

/* The C++ standard library defines  8 exception classes, we can also write our own exception classes */

// --- Catching Exception Objects by Const and Reference ---

/* Programs can catch exceptions by value, reference, const reference or pointer */

// ------------------------------------------------------------

// --- Throwing multiple exceptions ---

/* Failing to open from the file is not the only problem readIntegerFile() function can encounter. Another problem can encounter if the data read from the file is formatted incorrectly */
// void    readIntegerFile(const std::string& fileName, std::vector<int>& dest)
// {
//     std::ifstream istr;
//     int tmp;

//     istr.open(fileName.c_str());
//     if (istr.fail()) 
//     {
//         // Open failed: throw an exception
//         throw std::exception(); 
//     }

//     // Reading ints one by one and adding them to the vector
//     while (istr >> tmp)
//     {
//         dest.push_back(tmp);
//     }

//     if (istr.eof())
//     {
//         // End of file is reached
//         istr.close();
//     }
//     else {
//         // Some other error throw an exception
//         istr.close();
//         throw std::exception();
//     }
// } 

// int main(int argc, char** argv)
// {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     try {
//         readIntegerFile(fileName, myInts);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "Unable to open or to read file '" << fileName << "'" << std::endl;
//         exit(1);
//     }

//     for (size_t i = 0; i < myInts.size(); i++)
//     {
//         std::cout << myInts[i] << " ";
//     }
//     std::cout << std::endl;
//     return (0);
// } 

/* Alternatively wer can throw 2 different types of exception from readIntegerFile() function, so that the caller can tell which error occured. */

// void    readIntegerFile(const std::string& fileName, std::vector<int>& dest)
// {
//     std::ifstream istr;
//     int tmp;

   
//     istr.open(fileName.c_str());
//     if (istr.fail()) 
//     {
//         // Open failed: throw an exception
//         throw std::invalid_argument(""); 
//     }

//     // Reading ints one by one and adding them to the vector
//     while (istr >> tmp)
//     {
//         dest.push_back(tmp);
//     }

//     if (istr.eof()) {
//         // We reached the end of file
//         istr.close();
//     }
//     else {
//         // Some other error throw an exception
//         istr.close();
//         throw std::runtime_error("");
      
//     }
// } 

// int main(int argc, char** argv)
// {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     /* If an exception is thrown inside the try block, the compiler will match the type of the exception to the
//     proper catch handler. So, if readIntegerFile() is unable to open the file and throws in invalid_argument object, it will be caught by the first catch statement. If readIntegerFile() is unable to read the file properly and throws a runtime_error, then the second catch statement will catch the exception. */
//     try {
//         readIntegerFile(fileName, myInts);
//     } 
//     catch (const std::invalid_argument& e) {
//         std::cerr << "Unable to open file '" << fileName << "'" << std::endl;
//         exit(1);
//     } 
//     catch (const std::runtime_error& e) {
//         std::cerr << "Error reading file " << fileName << std::endl;
//         exit(1);
//     }

//     for (size_t i = 0; i < myInts.size(); i++)
//     {
//         std::cout << myInts[i] << " ";
//     }
//     std::cout << std::endl;
//     return (0);
// } 

// ---------------------------------------------------------------

// --- Matching and Const ---

/* The const-ness specified in the type of the exception you want to catch makes no difference for matching purposes. That is  
    catch (const runtime_error& e) 
    
mathes any exception of type runtime_error 
 This   catch (runtime_error& e) does the same thing
*/

/* ----
    You should generally catch exceptions with const to document that you are not
modifying them.
*/

// ------------------------------------------------------------

// --- Matching Any Exception ---

/* To match any type of exception we can do this */
// int main(int argc, char** argv)
// {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     try {
//         readIntegerFile(fileName, myInts);
//     } 
//     catch (...) /*  ... are not a typo. They are a wildcard that match any exception type. Whem you are calling poorly documented code, this technique cam be useful to ensure that you catch all possible exceptions. However, in situations where you have complete information about the set of thrown exceptions, this technique is considered suboptimal because it handles every exception type identically. It's better to match exception types explicitly and take appropriate, targeted action. */
//     {
//         std::cerr << "Error reading or opening file "  << fileName << std::endl;
//         exit(1);
//     } 

//     for (size_t i = 0; i < myInts.size(); i++)
//     {
//         std::cout << myInts[i] << " ";
//     }
//     std::cout << std::endl;
//     return (0);
// }

// ---------------------------------------------------------------

// --- Uncaught Exceptions ---

/* If your program throws an exception that is not caught anywhere, the program will terminate. This behavior is not usually what you want. 

Catch and handle all possible exceptions thrown in your programs.

It is also possible to change the behavior of your program if there is an uncaught exception. When the program encounters an uncaught exception, it calls the built-in `terminate()` function, which simply calls `abort()` from <cstdlib> to kill the program.

We can set our terminate_handler by calling `set_terminate()` with a pointer to a callback function thta takes no arguments and returns no value.

terminate(), set_terminate(), and terminate_handler are all declared in the <exception> header.

*/

/* Before you get too excited about this feature, you should know that your callback function must still terminate the program, or else `abort()` will be called anyway. It can’t just ignore the error. However, you can use it to print a helpful error message before exiting */
// void myTerminate()
// {
//     std::cout << "Uncaught exception\n";
//     exit(1);
// }

// int main(int argc, char** argv)
// {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     /* `set_terminate()` returns the old terminate_handler when it sets the new one. The `terminate_handler` applies program-wide, so it's considered good style to reset the old `terminate_handler` when you have completed the code that needed the new terminate_handler. In this case, the entire program needs the new_terminate, so there's no poiny in resetting it. Although  `set_terminate()`, it’s not a very effective exception-handling approach. It's recommended trying to catch and handle each exception individually in order to provide more precise error handling */
//     std::set_terminate(myTerminate);

//     readIntegerFile(fileName, myInts);

//     for (size_t i = 0; i < myInts.size(); i++)
//     {
//         std::cerr << myInts[i] << " ";
//     }
//     std::cout << std::endl;
//     return (0);
// }

// ----------------------------------------------------------

// --- Throw Lists ---

/* C++ allows you to specify the exceptions a function or method intends to throw. This specification is called the `throw list` or the `exception specification` */

// void    readIntegerFile(const std::string& fileName, std::vector<int>& dest)
// throw(std::invalid_argument, std::runtime_error) // throw list simply lists the types of exceptions that can be thrown from the function
// {
//     std::ifstream istr;
//     int tmp;

//     istr.open(fileName.c_str());
//     if (istr.fail()) 
//     {
//         // Open failed: throw an exception
//         throw std::invalid_argument(""); 
//     }

//     // Reading ints one by one and adding them to the vector
//     while (istr >> tmp)
//     {
//         dest.push_back(tmp);
//     }

//     if (istr.eof()) {
//         // We reached the end of file
//         istr.close();
//     }
//     else {
//         // Some other error throw an exception
//         istr.close();
//         throw std::runtime_error("");
      
//     }
// }

// Unlike const, the exception specification is not part of the function or method signature. You cannot overload a function based solely on different exceptions in the throw list.

// If a function or method specifies no throw list, it can throw any exception. If you want to specify that a function or method throws no exceptions, we need to write an empty throw list explicitly 
/* void readIntegerFile(const std::string& fileName, std::vector<int>& dest)
throw (); */

/* A function without a throw list can throw exceptions of any type. A function with an
empty throw list shouldn’t throw any exception. */

// ------------------------------------------------------

// --- Unexpected Exceptions ---

/* Unfortunately, the throw list is not enforced at compile time in C++. Code that calls readIntegerFile() does not need to catch the exceptions listed in the throw list. This behavior is different from that in other languages, such as Java, which requires a function or method to catch exceptions or declare them in their own function or method throw lists. */

// void readIntegerFile(const std::string& fileName, std::vector<int>& dest)
// throw (std::invalid_argument, std::runtime_error)
// {
//     throw (5);
// }

/* When this program runs and readIntegerFile() throws the int exception, the program terminates. It does not allow main() to catch the int. */
// int main(int argc, char** argv) {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     try {
//         readIntegerFile(fileName, myInts);
//     }
//     catch (int x) {
//         std::cerr << "Caught int\n";
//     }
//     return (0);
// }

// There is a way to change this behaviour
/*  Throw lists don't prevent functions from throwing unlisted exception types, but they prevent the excpetion from leaving the function 

When a function throws n exception that is not listed in its throw list, C++ calls a special function `unexpected()`. The built-in implementation of `unexpected()` simply calls `terminate()`. However, just as we can set our own `terminate_handler`, we can set your own `unexcpected_handler`. Unlike in the `terminate_handler`, we can actually do something other than just terminate the program in the `unexpected_handler`. Our version of the function must either throw a new exception or terminate the program - it can't just exit the function normally. 
     * If it throws a new exception, that exception will be substituted for the unexpected exception as if the new one had been originally. If this substituted exception is also not listed in the throw list, the program will do one of the two things
        1) If the throw list for function specifies `bad_exception`, then bad_exception will be thrown.
        2) Otherwise, the program will terminate.
*/

/* 
    Custom implementations of unexpected() are normally used to convert unexpected excepyions into excepted exceptions. For example, we could write a version of unexpected()  
*/

/* This code converts unexpected exception to a runtime_error exception, which the function readIntegerFile() has in its thrown list*/
// void myUnexpected()
// {
//     std::cout << "Unexpected exception!\n";
//     throw std::runtime_error("");
// }

/* We can set this unexpected exception handler witn the `set_unexpected()` function. Like set_terminate(), set_unexoected() returns the current handler. */
// int main(int argc, char** argv) {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     std::unexpected_handler old_handler = std::set_unexpected(myUnexpected);
//     try {
//         readIntegerFile(fileName, myInts);
//     }
//     catch (const std::invalid_argument& e) {
//         std::cerr << "Unable to open file " << fileName << std::endl;
//         exit(1);
//     }
//     catch (const std::runtime_error& e) {
//         std::cerr << "Error reading file " << fileName << std::endl;
//         exit(1);
//     }
//     catch (int x)
//     {
//         std::cout << "Caught int\n";
//     }
//     std::set_unexpected(old_handler);

//     for (size_t i = 0; i < myInts.size(); i++)
//         std::cout << myInts[i] << " ";
//     std::cout << std::endl;
//     return (0);
// }

// -----------------------------------------------------------------------------------

// --- Changing the Throw List in Overridden Methods ---

/*  When we override a virtual function method in a subclass, we can change the throw list as long as we make it more restrictive than the throw list in superclass. 

The following changes qualify as more restrictive: 
    * Removing exceptions from the list
    * Adding superclass of exceptions that appear in the superclass throw list

The following changes do not qualify as more restrictive: 
    * Adding exceptions to the list that are not subclass of exceptions in the superclass throw list
    * Removing the throw list entirely
*/

/*
    If you change throw lists when you override methods, remember that any code that
    called the superclass version of the method must be able to call the subclass version. Thus, you can’t add exceptions.
*/

// Superclass class
// class Base
// {
//     public:
//         virtual void func() throw(std::exception) {
//             std::cout << "Base\n";
//         }
// };

// // Subclass which overrides func()
// class Derived : public Base 
// {
//     public:
//         virtual void func() throw() {
//             std::cout << "Derived\n";
//         }
//         // Another override of func() which throws runtime_error as well as an exception, because runtime_error is a subclass of exception.
//         virtual void func() throw(std::exception, std::runtime_error) {
//             std::cout << "Derived\n";
//         }
// };

/* However, you cannot remove the throw list entirely, because that means func() could throw any exception. */

// class Base
// {
//     public:
//         virtual void func() throw(std::runtime_error) { 
//             std::cout << "Base!\n"; 
//         }
// };

// // You cannot then override func() in Derived with a throw list like this:
// class Derived : public Base
// {
//     public:
//         virtual void func() throw(std::exception) { // ERROR!
//             std::cout << "Derived!\n"; 
//         } 
// }; 

/* exception is a superclass of runtime_error, so you cannot substitute an exception for a runtime_error. */

// ----------------------------------------------------------------------------------

// --- Are Throw Lists Useful? ---

/* Given the opportunity to specify the behavior of a function in its signature, it seems wasteful not to take advantage of it. The exceptions thrown from a particular function are an important part of its interface, and should be documented as well as possible. */

// ----------------------------------------------------------------------------------

// --- Exceptions and Polymorphism ---
/* Classes are the most useful type of exceptions. In fact, exception classes are usually written in a hierarchy, so that we can employ polymorphism when we catch the exceptions. */

/* All of the exceptions thrown by the C++ Standard Library support a `what()` method that returns a `char*` string describing the exception. We can use this in an error message. */

/* all the exception classes except for the base exception class require you to set in the constructor the string that will be returned by what. That’s why we have to specify a string in the constructors for runtime_error and invalid_argument. */

// void readIntegerFile(const std::string& fileName, std::vector<int>& dst) 
//     throw(std::invalid_argument, std::runtime_error) {
//         std::ifstream istr;
//         int tmp;

//         istr.open(fileName.c_str());
//         if (istr.fail()) {
//             // We failed to open the file: throw an exception.
//             std::string error = "Unable to open the file " + fileName;
//             throw std::invalid_argument(error);
//         }

//         // Read the integers one by one and add them to the vector.
//         while (istr >> tmp) {
//             dst.push_back(tmp);
//         }

//         if (istr.eof()) {
//             // We reached the end-of-file.
//             istr.close();
//         }
//         else {
//             // Some other error. Throw an exception.
//             istr.close();
//             std::string error = "Unable to read file " + fileName;
//             throw std::runtime_error(error);
//         }
// }

// int main(int argc, char** argv) {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";

//     try {
//         readIntegerFile(fileName, myInts);
//     }
//     catch (const std::invalid_argument& e) {
//         std::cerr << e.what() << std::endl;
//         exit(1);
//     }
//     catch (const std::runtime_error& e) {
//         std::cerr << e.what() << std::endl;
//         exit(1);
//     }
//     catch (int x)
//     {
//         std::cout << "Caught int\n";
//     }

//     for (size_t i = 0; i < myInts.size(); i++)
//         std::cout << myInts[i] << " ";
//     std::cout << std::endl;
//     return (0);
// } 

// ---------------------------------------------------------------------------------

// --- Catching Exceptions in a Class Hierarchy ---

/* The most exciting feature of exception hierarchies is that you can catch exceptions polymorphically */
/* two catch statements in main() function above following the call to readIntegerFile(), you can see that they are identical except for the exception class that they handle. Conveniently, Handling Errors invalid_argument and runtime_error are both subclasses of exception, so you can replace the two catch statements with a single catch statement for class exception: */
// int main(int argc, char** argv) {
//     std::vector<int> myInts;
//     const std::string fileName = "IntegerFile.txt";
//     try {
//         readIntegerFile(fileName, myInts);
//     }
//     /* The catch statement for an exception reference matches any subclasses of exception, including both invalid_argument and runtime_error. Note that the higher in the exception hierarchy that you catch exceptions, the less specific is your error handling. We should generally catch exceptions at as specific a
//     level as possible. */
//     catch (std::exception& e) {
//         std::cerr << e.what() << std::endl;
//         exit(1);
//     }
//     for (size_t i = 0; i < myInts.size(); i++)
//         std::cout << myInts[i] << " ";
//     std::cout << std::endl;
// }

/* When you catch exceptions polymorphically, make sure to catch them by reference.
If you catch exceptions by value, you can encounter slicing, in which case you lose
information from the object. */

/* 
The polymorphic matching rules work on a “first come, first served” basic

C++ attempts to match the exception against each catch statement in order. The exception matches a catch statement if it is an object of that class or an object of a subclass of the class, even if a more exact match comes in a later catch statement.

*/

/* The first catch statement catches invalid_argument exceptions, and the second catches any other exceptions */
// int main(void) {
//     std::vector<int> myInts;
//     try {
//         readIntegerFile("IntegerFil.txt", myInts);
//     } catch (const std::invalid_argument& e) { // List the exception subclass first.
//         // Take some special action for invalid filenames.
//         std::cerr << "Inavlid file " << std::endl; 
//     } catch (const std::exception& e) { // Now list exception
//         std::cerr << e.what() << std::endl;
//     exit (1);
//     }
// }

/* Reversing catch statements */
/* With this order, any exception of a class that subclasses exception is caught by the first catch statement; the second will never be reached. Some compilers issue a warning in this case, but you shouldn’t count on it. */
// int main(void) {
//     std::vector<int> myInts;
//     try {
//         readIntegerFile("IntegerFile.txt", myInts);
//     } 
//     catch (const std::exception& e) { // BUG: catching superclass first!
//         std::cerr << e.what() << std::endl;
//         exit (1);
//     }
//     catch (const std::invalid_argument& e) {
//         std::cerr << "Inavlid file " << std::endl; 
//     } 
// }

// ---------------------------------------------------------------------------------

// --- Writing Your Own Exception Classes  ---

/* There are 2 advantages to writing your own exception classes 
    1. The number of exceptions in the C++ Standard Library is limited. Instead of using an exception class with a generic name, such as runtime_exception, you can create classes.

    2. You can add your own information to these exceptions. The exceptions in the standard hierarchy allow you to set only an error string. You might want to pass different information in the exception.
*/

class FileError: public std::runtime_error
{
    public:
        FileError(const std::string& fileIn) : std::runtime_error(""), m_file(fileIn) {}
        virtual ~FileError() throw() {} /* The destructor must be overridden in order to specify the throw list. The compiler-generated destructor has no throw list, which won’t compile, because runtime_error specifies an empty throw list. */

        /* what() has the signature shown and is supposed to return a char* string that is valid until the object is destroyed. In the case of FileError, this string comes from the mMsg data member, which is set to “” in the constructor. Subclasses of FileError must set this mMsg string to something different if they want a different message. */
        virtual const char* what() const throw() {
            return m_msg.c_str();
        }

    protected:
        std::string m_file;
        std::string m_msg;
};

// The first exceptional situation in readIntegerFile() occurs if the file cannot be opened

class FileOpenError : public FileError {
    public:
        FileOpenError(const std::string& fileNameIn);
        virtual ~FileOpenError() throw() {}
};

FileOpenError::FileOpenError(const std::string& fileNameIn) : FileError(fileNameIn) {
    m_msg = "Unable to open " + fileNameIn;
}

// The second exceptional situation in readIntegerFile() occurs if the file cannot be read properly. It might be useful for this exception to contain the line number of the error in the file, as well as the filename and the error message string returned from what(). 

class FileReadError : public FileError{
    public:
        FileReadError(const std::string& fileNameIn, int lineNumIn);
        virtual ~FileReadError() throw() {}
        
        int getLineNum() const {
            return m_line_num;
        }
    protected:
        int m_line_num;
};

#include <sstream>
FileReadError::FileReadError(const std::string& fileNameIn, int lineNumIn) : FileError(fileNameIn), m_line_num(lineNumIn) {

    std::ostringstream ostr;

    ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
    m_msg = ostr.str();
} 

void readIntegerFile(const std::string& fileName, std::vector<int>& dest)
throw (FileOpenError, FileReadError) {
    std::ifstream istr;
    int tmp;
    char line[1024]; // // Assume that no line is longer than 1024 characters.
    int lineNumber = 0;

    istr.open(fileName.c_str());
    if (istr.fail()) {
        // We failed to open the file: throw an exception.
        throw FileOpenError(fileName);
    }

    while (!istr.eof()) {
        // Read one line from the file.
        istr.getline(line, 1024);
        lineNumber++;

        // Create a string stream out of the line.
        std::istringstream lineStream(line);

        // Read the integers one by one and add them to the vector.
        while (lineStream >> tmp) {
            dest.push_back(tmp);
        }
        if (!lineStream.eof()) {
            // Some other error. Close the file and throw an exception.
            istr.close();
            throw FileReadError(fileName, lineNumber);
        }
    }
    istr.close();
}

int main(void) {
    std::vector<int> myInts;
    try {
        readIntegerFile("IntegerFile.txt", myInts);
    }
    catch (const FileError& e) { 
        std::cerr << e.what() << std::endl;
        exit (1);
    }
}

/* There is one trick to writing classes whose objects will be used as exceptions. When a piece of code throws an exception, the object or value thrown is copied. That is, a new object is constructed from the old object using the copy constructor. It must be copied because the original could go out of scope (and be destroyed and have its memory reclaimed) before the exception is caught, higher up in the stack. Thus,
if you write a class whose objects will be thrown as exceptions, you must make those objects copyable.
This means that if you have dynamically allocated memory, you must write a destructor, copy constructor, and assignment operator */

// Objects thrown as exceptions are always copied by value at least once.
// Catch exception objects by reference to avoid unnecessary copying.