#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(const point_t & center_, double width_, double height_) :
    center(center_),
    width(width_),
    height(height_)
{
    assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
    return (width * height);
}

rectangle_t Rectangle::getFrameRect() const
{
    return {width,height,center};
}

void Rectangle::move(const point_t & position)
{
    center = position;
}

void Rectangle::move(double shift_x, double shift_y)
{
    center.x += shift_x;
    center.y += shift_y;
}
