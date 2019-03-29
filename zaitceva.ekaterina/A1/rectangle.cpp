#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double wdth, double hght, point_t ps)
{
    width_ = wdth;
    height_ = hght;
    pos_ = ps;
    assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea () const
{
    return width_*height_;
}
rectangle_t Rectangle::getFrameRect () const
{
    return {width_, height_, pos_};
}
void Rectangle::move (point_t pnt)
{
    pos_ = pnt;
}
void Rectangle::move (double abs, double ord)
{
    pos_.x = pos_.x+abs;
    pos_.y = pos_.y + ord;
}
