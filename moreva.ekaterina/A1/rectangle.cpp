#include "rectangle.hpp"
#include <iostream>
#include <cassert>


Rectangle::Rectangle(const point_t & pos,double width,double height) :
  center_(pos),
  width_(width),
  height_(height)
{
  assert((width > 0) && (height > 0));
}

Rectangle::Rectangle(double posX, double posY, double width, double height):
    Rectangle({posX,posY}, width, height)
{
}

double Rectangle::getArea() const
{
    return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const point_t & pos)
{
    center_ = pos;
}

void Rectangle::move(const double deltaX, const double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void Rectangle::printInfo() const
{
  std::cout << "Rectangle. It's center is at " <<"("<< center_.x << ";" << center_.y << ")"
    << std::endl << "width is : " << width_<< std::endl << "Height is : " << height_
      << std::endl << "Area is : " << getArea() << std::endl << std::endl;
}
