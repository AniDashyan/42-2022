#include <iostream>
#include <string>

// struct Vector2 {
//     float x, y;
// };

// int main() {
//     // int a = 2;
//     /* copies vector struct itself */
//     // Vector2 a = {2, 3};
//     // Vector2 b = a;

//     /* In this we way we are copying something,
//     but not the actual struct which contains the actual values.
//     We are actually copying the pointer */
//     Vector2 *a = new Vector2();
//     Vector2 *b = a; // When using assignmenyt we are always copying 
//     /* Here we are not affecting pointer, we are affecting memory address */
//     b->x = 2;


//     /* b copies the value of a */
//     // int b = a;
//     // std::cout << b << std::endl;
//     return (0);
// }

class String {
    private:
        char *m_Buffer;
        unsigned int m_Size;
    public:
        String(const char* string) {
            m_Size = strlen(string);
            m_Buffer = new char[m_Size + 1];
            // for (int i = 0; i < m_Size; i++)
            //     m_Buffer[i] = string[i];
            /* more concise way to write it */
            memcpy(m_Buffer, string, m_Size);
            m_Buffer[m_Size] = 0;
        }

        /* C++ calls copy constructor automatically.
        It actually does memcpy. It's going to shallow copy the memory of other object 
        to private members of a String class */
        // String(const String& other)
        //     : m_Buffer(other.m_Buffer), m_Size(other.m_Size) {

        //     }

        /* More exciting way */
        // String(const String& other) {
        //     memcpy(this, &other, sizeof(String));
        // }

        /* If we dont want copy constructor we can do this 
           String(const String& other) = delete;
        */

       /* Doing deep copy with copy constructor */
       // ALWAYS PASS OBJECTS WITH [CONST REFERENCE]
       String(const String& other) : m_Size(other.m_Size)
       {
         std::cout << "copy Constructor: Copied String!\n";
         m_Buffer = new char[m_Size + 1];
         memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
       }

        ~String() {
            delete [] m_Buffer;
        }

        char& operator[](unsigned int index) {
            return m_Buffer[index];
        }

        friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream <<  string.m_Buffer;
    return stream;
}

// Tthis won't modify string that's we pass string as const
// If we don't mark it as a const reference
// It means not only we edit it
void PrintString(const String& string)
{
    // string[2] = '7';
    // If we actually want to copy
    String copy = string;
    std::cout << string << std::endl;
}

/* Shallow copy */
/* int main() {
    // the code crashes this way, because we do shallow copy
    // second copies the members of a String class (C++ does it automatically)
    // second copies the members of String class into a new memory address which contains second
    // In memory we have direct copy(in other words shallow copy), which copied the pointer and we have 2 pointers pointing at the same values
    String string = "Cherno";
    String second = string;

    second[2] = 'a';

    std::cout << string << std::endl;
    std::cout << second << std::endl;
    return (0);
} */

// int main() {
//     String string = "Cherno";
//     String second = string;

//     second[2] = 'a';

//     // std::cout << string << std::endl;
//     // std::cout << second << std::endl;

//     /* Alternative to the couts above */
//     PrintString(string);
//     PrintString(second);
//     return (0);
// }