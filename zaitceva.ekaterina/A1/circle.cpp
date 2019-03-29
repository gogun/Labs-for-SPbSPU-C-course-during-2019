#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(point_t centre, double rad)
{
    pos_ = centre;
    radius_ = rad;
    assert (radius_ > 0.0);
}
double Circle::getArea () const
{
    return M_PI*radius_*radius_;
}
void Circle::move(point_t pnt)
{
    pos_ = pnt;
}
void Circle::move(double abs, double ord)
{
    pos_.x = pos_.x + abs;
    pos_.y = pos_.y + ord;
}
rectangle_t Circle::getFrameRect() const
{
    return {2*radius_, 2*radius_, pos_};
}
