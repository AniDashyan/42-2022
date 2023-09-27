#include <iostream>
#include <fstream>
#include <vector>
// Header file for handling exceptions
#include <exception>
#include <string>
// the header file from where invalid_argument and runtime_exception come from
#include <stdexcept>

// Throwing and Catching Exceptions
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

// ----------------------------------------------------------------------------------

/* Although by default streams do not throw exceptions, you can tell the streams to throw exceptions for
error conditions by calling their exceptions() method. However, no less a luminary than Bjarne Stroustrup (who created C++) recommends against this approach. In The C++ Programming Language, third edition, he says “ . . . I prefer to deal with the stream state directly. What can be handled with local control structures within a function is rarely improved by the use of exceptions.” */

// ----------------------------------------------------------------------------------

// Exception Types
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
// --------------------------------------------------------------------------------

/* However we should throw objects as exceptions for 2 reasons 
        1) Objects convey information by their class name
        2) Objects can store information, such as strings, that describe the exceptions
*/

// --------------------------------------------------------------------------------

/* The C++ standard library defines  8 exception classes, we can also write our own exception classes */

// Catching Exception Objects by Const and Reference
/* Programs can catch exceptions by value, reference, const reference or pointer */

// --------------------------------------------------------------------------------

// Throwing multiple exceptions

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

// --------------------------------------------------------------------------------

//  Matching and Const
/* The const-ness specified in the type of the exception you want to catch makes no difference for matching purposes. That is  
    catch (const runtime_error& e) 
    
mathes any exception of type runtime_error 
 This   catch (runtime_error& e) does the same thing
*/

/* ----
    You should generally catch exceptions with const to document that you are not
modifying them.
*/

// --------------------------------------------------------------------------------

// Matching Any Exception
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

// -----------------------------------------------------------------

// Uncaught Exceptions

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

// -------------------------------------------------------------------------

// Throw Lists

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

// ------------------------------------------------------------------------------------

// Unexpected Exceptions
/* Unfortunately, the throw list is not enforced at compile time in C++. Code that calls readIntegerFile() does not need to catch the exceptions listed in the throw list. This behavior is different from that in other languages, such as Java, which requires a function or method to catch exceptions or declare them in their own function or method throw lists. */

void readIntegerFile(const std::string& fileName, std::vector<int>& dest)
throw (std::invalid_argument, std::runtime_error)
{
    throw (5);
}

/* When this program runs and readIntegerFile() throws the int exception, the program terminates. It does not allow main() to catch the int. */
int main(int argc, char** argv) {
    std::vector<int> myInts;
    const std::string fileName = "IntegerFile.txt";

    try {
        readIntegerFile(fileName, myInts);
    }
    catch (int x) {
        std::cerr << "Caught int\n";
    }
    return (0);
}

// There is a way to change this behaviour
/*  Throw lists don't prevent functions from throwing unlisted exception types, but they prevent the excpetion from leaving the function 

When a function throws n exception that is not listed in its throw list, C++ calls a special function `unexpected()`. The built-in implementation of `unexpected()` simply calls `terminate()`. However, just as 

*/