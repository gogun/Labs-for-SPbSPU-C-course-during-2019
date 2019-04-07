#include "rectangle.hpp"
#include "cassert"

Rectangle::Rectangle(const point_t &center, const double &width, const double &height):
    center_(center),
    width_(width),
    height_(height)
{
    assert((width_ > 0) && (height_ > 0));
}

double Rectangle::getArea() const
{
    return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
    return {width_, height_, center_};
}

void Rectangle::move(const point_t &position)
{
    center_ = position;
}

void Rectangle::move(const double &move_x, const double &move_y)
{
    center_.x += move_x;
    center_.y += move_y;
}
