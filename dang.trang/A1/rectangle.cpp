#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(point_t point, const double width, const double height): Shape(point),width_(width),height_(height)
{
};

double Rectangle::getArea() const
{
  double area=0;
  area = width_*height_;
  return area;
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frame={ 1,1,{0,0} };
  frame.height = height_;
  frame.width = width_;
  frame.pos.x = center_.x;
  frame.pos.y = center_.y;
  return frame;
}

void Rectangle::prInf() const
{
  std::cout << "Centre on Ox " << center_.x << " centre on Oy " << center_.y<<std::endl;
  std::cout << "Rectangle  width = " << width_ << " height = " << height_ << std::endl;
}
