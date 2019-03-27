#include "circle.hpp"
#include <math.h>
#include <iostream>
#include <cassert>

Circle::Circle(point_t pos, double radius) :
    pos_(pos),
    radius_(radius)
{
    assert(radius_ > 0);
}

double Circle::getArea() const
{
    return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
    return {2 * radius_, 2 * radius_, pos_};
}

void Circle::move(point_t point)
{
    pos_ = point;
}

void Circle::move(double dx, double dy)
{
    pos_.x += dx;
    pos_.y +=dy;
}

void Circle::printInfo() const
{
    rectangle_t rectangle = getFrameRect();
    std::cout << "Circle's center (" << pos_.x
              << "," << pos_.y << ")\n"
              <<"Rectangle frame width = " << rectangle.width
              <<"\nRectangle frame height = " << rectangle.height
              << ";\nArea = " << getArea() << "\n";
}
