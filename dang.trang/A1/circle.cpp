#include "circle.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

const double M_PI= 3.14;

Circle::Circle(const point_t &pos,const double radius):
  center_(pos),
  radius_(radius)
{
  if(radius_ <= 0)
  {
    throw std::invalid_argument("Invalid circle parameters!");
  }
}
void Circle::move(const double dx,const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
void Circle::move(const point_t &new_p)
{
  center_ = new_p;
}
double Circle::getArea() const
{
  return M_PI*radius_*radius_;
}
rectangle_t Circle::getFrameRect() const
{
  return {center_,2*radius_,2*radius_};
}
void Circle::print() const
{
  cout<<"----Circle: \n";
  cout<<"  center: ("<<center_.x<<", "<<center_.y<<") \n";
  cout<<"  radius = "<<radius_<<endl;
  cout<<"  Area = "<<getArea()<<endl;
  cout<<"  FrameRect for Circle: \n";
  cout<<"     center: ("<<getFrameRect().pos.x<<", "<<getFrameRect().pos.y<<") width= "<<getFrameRect().width<<"  height= "<<getFrameRect().height<<endl;
}
