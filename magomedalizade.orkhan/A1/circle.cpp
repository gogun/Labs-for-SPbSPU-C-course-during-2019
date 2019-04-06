#include "Circle.hpp"
#include <stdexcept>
#include <iostream>

double const M_PI=3.14159265358;

Circle::Circle(const point_t &place, const double radius):
  Shape(place),
  radius_(radius)
{ 
  if (radius<=0) 
  {
    throw std::invalid_argument("negative radius");
  }
};

rectangle_t Circle::getFrameRect() const
{
  return{place_,radius_*2,radius_*2};
};

double Circle::getArea() const
{
  return M_PI*radius_*radius_;
};

void Circle::getInfo() const

{
  std::cout<<"Placement of the circle: "<<place_.x<<" "<<place_.y<<"\n";
  std::cout<<"Radius of the circle: "<<radius_<<"\n";
};

point_t Circle::getPlace() const
{
  return(place_);