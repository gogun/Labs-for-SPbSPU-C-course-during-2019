#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <iostream>
#include <math.h>

Circle::Circle(point_t point, const double radius):Shape(point),radius_(radius)
{
}

double Circle::getArea() const
{
  double area=0;
  area = (M_PI *(radius_*radius_));
  return area;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t frame={ 1,1,{0,0} };
  frame.height = radius_;
  frame.width = radius_;
  frame.pos.x = center_.x;
  frame.pos.y = center_.y;
  return frame;
}

void Circle::prInf() const
{
  std::cout << "Centre on Ox " << center_.x << " centre on Oy " << center_.y<<std::endl;
  std::cout << "Circle radius = "<<radius_<<std::endl;
}
