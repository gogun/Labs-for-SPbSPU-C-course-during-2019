#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
Circle::Circle(const double radius, const point_t& center):
  radius_(radius),
  center_(center)
{
  assert(radius > 0.0);
}
double Circle::getArea() const
{
  return M_PI*radius_*radius_;
}
rectangle_t Circle::getFrameRect() const
{
  return {2*radius_, 2*radius_, center_};
}
void Circle::move(const double changeX, const double changeY)
{
  center_.x+=changeX;
  center_.y+=changeY;
}
void Circle::move(const point_t & newCenter)
{
  center_=newCenter;
}
void Circle::printInformation() const
{
  std::cout<<"Center of the circle is "<< center_.x<<","<< center_.y<<"\n";
  std::cout<<"Circle radius is "<< radius_<<"\n";
  std::cout<<"Area of the circle is "<<getArea()<<"\n";
  std::cout<<"Parameters of the frame rectangle: "<<"\n";
  std::cout<<"Width: "<<getFrameRect().width <<"\n";
  std::cout<<"Height: "<<getFrameRect().height <<"\n";
  std::cout<<"Center: ("<<getFrameRect().pos.x <<","<<getFrameRect().pos.y<<")\n";
}