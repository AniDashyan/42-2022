#include "Fixed.hpp"

Fixed::Fixed() : m_fp_value(0) {
    std::cout << "Default Constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy Constructor called\n";
    this->m_fp_value = other.m_fp_value;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy Assignment Operator called\n";
    if (this != &other)
        this->m_fp_value = other.m_fp_value;
    return (*this); 
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (this->m_fp_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->m_fp_value = raw;
}