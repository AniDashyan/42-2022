#include "Point.hpp"

Fixed ft_abs(Fixed num) {
    return (num < 0 ? (num * (-1)) : num);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = ft_abs(((a.getX() * b.getY()) + (b.getX() * c.getY()) + (c.getX() * a.getY()) - (a.getX() * c.getY()) - (c.getX() * b.getY()) - (b.getX() * a.getY()))) / 2;
    Fixed areaABP = ft_abs(((a.getX() * b.getY()) + (b.getX() * point.getY()) + (point.getX() * a.getY()) - (a.getX() * point.getY()) - (point.getX() * b.getY()) - (b.getX() * a.getY()))) / 2;
    Fixed areaAPC = ft_abs(((a.getX() * point.getY()) + (point.getX() * c.getY()) + (c.getX() * a.getY()) - (a.getX() * c.getY()) - (c.getX() * point.getY()) - (point.getX() * a.getY()))) / 2;
    Fixed areaPBC = ft_abs(((point.getX() * b.getY()) + (b.getX() * c.getY()) + (c.getX() * point.getY()) - (point.getX() * c.getY()) - (c.getX() * b.getY()) - (b.getX() * point.getY()))) / 2;

    return (areaABC == areaABP + areaAPC + areaPBC);
}