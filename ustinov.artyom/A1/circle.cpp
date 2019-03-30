#include "circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle()
{
}

Circle::Circle(double xx, double yy, double radius) :
radius_(radius)
{
  center_.x = xx;
  center_.y = yy;
}

Circle::Circle(point_t goal, double rad) :
center_(goal),
radius_(rad)
{
}

double Circle::getArea() const
{
  return M_PI*radius_*radius_;
}

rectangle_t Circle::getFrameRect() const
{
  
  rectangle_t rectmp;
  rectmp.width=2*radius_;
  rectmp.height=2*radius_;
  rectmp.pos=center_;
  
  return rectmp;
}

void Circle::move(point_t goal)
{
  center_ = goal;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::show() const
{
  std::cout << "\nCircle center: " << center_.x << " , " << center_.y << std::endl;
  std::cout << "Circle radius: " << radius_ << std::endl;
}
