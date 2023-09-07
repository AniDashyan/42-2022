#include "Point.hpp"

Point::Point() : m_x(0), m_y(0) {
    std::cout << "Default Constructor called\n";
}

Point::Point(const float x, const float y) : m_x(x), m_y(y) {
    std::cout << "Constructor with parameters called\n";
}

Fixed Point::getX() const {
    return (this->m_x);
}

Fixed Point::getY() const {
    return (this->m_y);
}

Point::Point(const Point& other): m_x(other.getX()), m_y(other.getY()) {
    std::cout << "Copy Constructor called\n";
}

Point& Point::operator=(const Point &other) {
    if (this != &other) {
        // Solve the const problem
        this->m_x = other.getX();
        this->m_y = other.getY();
    }
    return (*this);
}

Point::~Point() {
    std::cout << "Destructor called\n";
}