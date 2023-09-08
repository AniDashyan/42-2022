#include "Point.hpp"

Point::Point() : m_x(0), m_y(0) {
    // std::cout << "Default Constructor of Point called" << std::endl;
}

Point::Point(const float x, const float y) : m_x(x), m_y(y) {
    // std::cout << "Constructor with parameters of Point called" << std::endl;
}

Fixed Point::getX() const {
    return (this->m_x);
}

Fixed Point::getY() const {
    return (this->m_y);
}


Point::Point(const Point& other): m_x(other.getX()), m_y(other.getY()) {
    // std::cout << "Copy Constructor of Point called" << std::endl;
}

Point& Point::operator=(const Point &other) {
    if (this != &other) {
        (Fixed)this->m_x = other.getX();
        (Fixed)this->m_y = other.getY();
    }
    // std::cout << "Copy Assignment Operatot of Point called" << std::endl;
    return (*this);
}


Point::~Point() {
    // std::cout << "Destructor of Point called\n";
}