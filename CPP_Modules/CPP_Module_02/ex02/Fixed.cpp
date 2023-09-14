#include "Fixed.hpp"

Fixed::Fixed() : m_fp_value(0) {
    std::cout << "Default Constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
    this->m_fp_value = other.m_fp_value;
    std::cout << "Copy Constructor called\n";
}

Fixed::Fixed(const int integer) {
    this->m_fp_value = integer * (1 << m_num_of_bits);
    std::cout << "Constructor with integer parameter called\n";
}

Fixed::Fixed(const float float_num) {
    this->m_fp_value = roundf(float_num * (1 << m_num_of_bits));
    std::cout << "Constructor with float parameter called\n";
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

float Fixed::toFloat(void) const {
    return ((float)this->m_fp_value / (1 << 8));
}

int Fixed::toInt(void) const {
    return (this->m_fp_value / (1 << 8));
}

bool Fixed::operator>(const Fixed& other) {
    return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) {
    return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other) {
    return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) {
    return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed& other) {
    return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) {
    return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) {
    Fixed c;
    
    c.setRawBits(this->getRawBits() + other.getRawBits());
    return (c);
}

Fixed Fixed::operator-(const Fixed& other) {
    Fixed c;
    
    c.setRawBits(this->getRawBits() - other.getRawBits());
    return (c);
}

Fixed Fixed::operator*(const Fixed& other) {
    Fixed c;
    
    c.setRawBits(((this->toFloat() * other.toFloat()) * (1 << m_num_of_bits)));
    return (c);
}

Fixed Fixed::operator/(const Fixed& other) {
    Fixed c;
    
    c.setRawBits((this->toFloat() / other.toFloat()) * (1 << m_num_of_bits));
    return (c);
}

Fixed  Fixed::operator++(int) {
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return (tmp);
}

Fixed  Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed  Fixed::operator--(int) {
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return (tmp);
}

Fixed  Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed& Fixed::min(Fixed &num1, Fixed &num2) {
    return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}

const Fixed& Fixed::min(const Fixed &num1, const Fixed &num2)
{
    return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2) {
    return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}

const Fixed& Fixed::max(const Fixed &num1, const Fixed &num2) {
    return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& other) {
    stream << other.toFloat();
    return (stream);
}