#include "circle.hpp"
#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <stdexcept>

Circle::Circle(const point_t &centre, const double &radius) :
  Shape(centre),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("radius <= 0");
  }
}
void Circle::setRadius(const double &radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("radius <= 0");
  }
  radius_ = radius;
}
double Circle::getRadius() const
{
  return radius_;
}
double Circle::getArea() const
{
  return (radius_ * radius_ * M_PI);
}
rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{ radius_, radius_, pos_ };
}
void Circle::move(const point_t &to_position)
{
  pos_ = to_position;
}
void Circle::move(const double &dx, const double &dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
void Circle::printShapeInfo() const
{
  std::cout << "Circle info" << "\n";
  std::cout << "Centre is in " << " X= " << pos_.x << " Y= " << pos_.y << "\n";
  std::cout << "Radius is " << radius_ << "\n";
}
