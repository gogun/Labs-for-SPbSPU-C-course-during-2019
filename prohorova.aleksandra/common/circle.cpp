#include "circle.hpp"
#include <iostream>
#include <cmath>

prohorova::Circle::Circle(const point_t& pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius of circle must be a positive number.\n");
  }
}
prohorova::Circle::Circle(double posX, double posY, double radius):
  Circle(point_t{posX, posY}, radius)
{
}
double prohorova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}
prohorova::rectangle_t prohorova::Circle::getFrameRect() const
{
  return rectangle_t{pos_, radius_ * 2, radius_ * 2};
}
void prohorova::Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}
void prohorova::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
void prohorova::Circle::show() const
{
  std::cout << "Circle. Radius = " << getRadius();
  std::cout << ", position of centre = (" << getPos().x << " , " << getPos().y << "), ";
  std::cout << "area = " << getArea();
  rectangle_t frame = getFrameRect();
  std::cout << "\n\tFrame rectangle: centre(" << frame.pos.x << ", " << frame.pos.y << ")";
  std::cout << ", width = " << frame.width << ", height = " << frame.width << ".\n";
}
void prohorova::Circle::scale(double factor)
{
  radius_ *= factor;
}
const prohorova::point_t& prohorova::Circle::getPos() const
{
  return pos_;
}
double prohorova::Circle::getRadius() const
{
  return radius_;
}
