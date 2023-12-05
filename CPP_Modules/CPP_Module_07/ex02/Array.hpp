#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](size_t index);
        ~Array();

        size_t size() const;
    private:
        size_t m_size;
        T* m_element;
};

template <typename T>
Array<T>::Array() : m_size(0), m_element(NULL) {
    
}

template <typename T>
Array<T>::Array(unsigned int n) {
    this->m_element = new T[n];
    for (size_t i = 0; i < n; i++)
    {
        this->m_element[i] = 0;
    }
    this->m_size = n;
}

template <typename T>
Array<T>::Array(const Array<T>& other) {
    m_element = new T[other.m_size];
    for (size_t i = 0; i < other.m_size; i++)
        this->m_element[i] = other.m_element[i];

    this->m_size = other.m_size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other)
    {
        delete [] m_element;
        m_element = new T[other.m_size];
        for (size_t i = 0; i < other.m_size; i++)
            this->m_element[i] = other.m_element[i];

        this->m_size = other.m_size;
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() {
    delete [] m_element;
}

template <typename T>
size_t Array<T>::size() const {
    return (this->m_size);
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (!(this->m_element))
        throw std::invalid_argument("Error: Empty Array");
    if (index > this->m_size - 1 || index < 0)
        throw std::out_of_range("Error: Index is out of range");

    return (this->m_element[index]);
}



#endif