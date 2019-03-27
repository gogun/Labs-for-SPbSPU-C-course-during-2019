#include "rectangle.hpp"
#include "iostream"

Rectangle::Rectangle(const rectangle_t& rect)
{
  Rectangle(rect.width,rect.height,rect.pos.x,rect.pos.y);
}

Rectangle::Rectangle(double w,double h,const point_t& pos)
{
  Rectangle(w,h,pos.x,pos.y);
}

Rectangle::Rectangle(double w,double h,double pos_x,double pos_y)
{
  rect_.width = w,
  rect_.height = h,
  rect_.pos.x = pos_x;
  rect_.pos.y = pos_y;
  if (w<=0)
  {
    std::cerr << "Width must be > 0";
  }
  if (h<=0)
  {
    std::cerr << "Height must be > 0";
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
