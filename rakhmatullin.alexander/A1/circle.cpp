#include "circle.hpp"

#include <cassert>

const double pi = 3.14159265;

Circle::Circle(const point_t & position, double radius_) :
    center(position),
    radius(radius_)
{
    assert(radius > 0.0);
}

double Circle::getArea() const
{
    return (pi * radius * radius);
}

rectangle_t Circle::getFrameRect() const
{
    return {2 * radius, 2 * radius, center};
}

void Circle::move(double shift_x, double shift_y)
{
    center.x += shift_x;
    center.y += shift_y;
}

void Circle::move(const point_t & position)
{
    center = position;
}
