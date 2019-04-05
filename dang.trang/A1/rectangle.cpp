#include "Rectangle.hpp"
#include <iostream>
#include <stdexcept>


using namespace std;

Rectangle::Rectangle(const point_t &pos,const double width,const double height):
  rect_({pos,width,height})
{
  if((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Invalid Rectangle parameters!");
  }
}
void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}
void Rectangle::move(const point_t &new_p)
{
  rect_.pos = new_p;
}
double Rectangle::getArea() const
{
  return rect_.width*rect_.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}
void Rectangle::print() const
{
  cout<<"----Rectangle: \n";
  cout<<"  center: ("<<rect_.pos.x<<", "<<rect_.pos.y<<") \n";
  cout<<"  width = "<<rect_.width<<" \t  height = "<<rect_.height<<endl;
  cout<<"  Area = "<<getArea()<<endl;
  cout<<"  FrameRect for rectangle: \n";
  cout<<"     center: ("<<getFrameRect().pos.x<<", "<<getFrameRect().pos.y<<") width= "<<getFrameRect().width<<" height= "<<getFrameRect().height<<endl;
}
