#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
    private:
        Fixed const m_x;
        Fixed const m_y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point &other);

        Fixed getX() const;
        Fixed getY() const;

        ~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif