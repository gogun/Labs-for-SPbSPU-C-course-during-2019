#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t& center):
  width_(width),
  height_(height),
  center_(center)
{
  assert((width > 0) && (height > 0));
}
double Rectangle::getArea() const
{
  return width_*height_;
}
rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}
void Rectangle::move(const double changeX, const double changeY)
{
  center_.x+=changeX;
  center_.y+=changeY;
}
void Rectangle::move(const point_t & newCenter)
{
  center_=newCenter;
}
void Rectangle::printInformation() const
{
  std::cout<<"Center of the rectangle is "<< center_.x<<","<< center_.y<<"\n";
  std::cout<<"Rectangle\'s width is "<< width_<<"\n";
  std::cout<<"Rectangle\'s height is "<<height_<<"\n";
  std::cout<<"Area of the rectangle is "<<getArea()<<"\n";
  std::cout<<"Parameters of the frame rectangle: "<<"\n";
  std::cout<<"Width: "<<getFrameRect().width <<"\n";
  std::cout<<"Height: "<<getFrameRect().height <<"\n";
  std::cout<<"Center: ("<<getFrameRect().pos.x <<","<<getFrameRect().pos.y<<")\n";
}
