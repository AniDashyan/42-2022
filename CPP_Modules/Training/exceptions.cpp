#include <iostream>
#include <fstream>
#include <vector>
// Header file for handling exceptions
#include <exception>
#include <string>


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
error conditions by calling their exceptions() method. However, no less a luminary than Bjarne
Stroustrup (who created C++) recommends against this approach. In The C++ Programming
Language, third edition, he says “ . . . I prefer to deal with the stream state directly. What can be handled with local control structures within a function is rarely improved by the use of exceptions.” */

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

// the header file from where invalid_argument and runtime_exception come from
#include <stdexcept>
void    readIntegerFile(const std::string& fileName, std::vector<int>& dest)
{
    std::ifstream istr;
    int tmp;

   
    istr.open(fileName.c_str());
    if (istr.fail()) 
    {
        // Open failed: throw an exception
        throw std::invalid_argument(""); 
    }

    // Reading ints one by one and adding them to the vector
    while (istr >> tmp)
    {
        dest.push_back(tmp);
    }

    if (istr.eof()) {
        // We reached the end of file
        istr.close();
    }
    else {
        // Some other error throw an exception
        istr.close();
        throw std::runtime_error("");
      
    }
} 

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
int main(int argc, char** argv)
{
    std::vector<int> myInts;
    const std::string fileName = "IntegerFile.txt";

    try {
        readIntegerFile(fileName, myInts);
    } 
    catch (...) {
        std::cerr << "Error reading or opening file "  << fileName << std::endl;
        exit(1);
    } 

    for (size_t i = 0; i < myInts.size(); i++)
    {
        std::cout << myInts[i] << " ";
    }
    std::cout << std::endl;
    return (0);
} 