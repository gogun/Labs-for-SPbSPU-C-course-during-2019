#include "rectangle.hpp"
#include "iostream"

Rectangle::Rectangle(const point_t &center,double width,double height) :
  rect_({width,height,center})
{
  if ((rect_.width <= 0) || (rect_.height <= 0))
  {
    std::cerr << "Invalid rectangle params!" << std::endl;
  }
}

double Rectangle::getArea() const
{
  return rect_.width*rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::coutInfo() const
{
  std::cout << "Rectangle at " << "("<< rect_.pos.x << "," << rect_.pos.y << ")" << std::endl;
  std::cout << "Width: " << rect_.width << ", " << "height: " << rect_.height << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
}

void Rectangle::move(double x,double y)
{
  rect_.pos.x+=x;
  rect_.pos.y+=y;
}

void Rectangle::move(const point_t &pos)
{
  rect_.pos = pos;
}
