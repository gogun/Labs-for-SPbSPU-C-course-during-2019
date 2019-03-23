#include "circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle(double posX,double posY,double radius):
  pos_(point_t{posX,posY}),
  radius_(radius)
{
  check();
}
Circle::Circle(const point_t &pos,double radius):
  pos_(pos),
  radius_(radius)
{
  check();
}
double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}
rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{getPos(),getRadius(), getRadius()};
}
void Circle::move(const point_t &newPos)
{
  pos_ = newPos;
}
void Circle::move(double dx,double dy)
{
  pos_ = point_t{getPos().x+dx,getPos().y + dy};
}
void Circle::show() const
{
  std::cout << "Circle. Radius = " << getRadius();
  std::cout << ", position of centre = (" << getPos().x << " , " << getPos().y << "), ";
  std::cout << "area = " << getArea();
  rectangle_t frame = getFrameRect();
  std::cout << "\n\tFrame rectangle: centre(" << frame.pos.x << ", " << frame.pos.y << ")";
  std::cout << ", width = " << frame.width << ", height = " << frame.width << ".\n";
}
const point_t& Circle::getPos() const
{
  return pos_;
}
double Circle::getRadius() const
{
  return radius_;
}
void Circle::check() const
{
  if(radius_ <= 0)
  {
    std::cout << "Radius of circle must be a positive number.\n";
  }
}
