#include "circle.hpp"

#include <cassert>
#include <iostream>
#include <cmath>

Circle::Circle(const point_t &center, const double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

Circle::Circle(const double x, const double y, const double radius) :
  center_({x,y}),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{center_, radius_, radius_};
}

void Circle::move(const point_t &position)
{
  center_ = position;
}

void Circle::move(const double xx, const double yy)
{
  center_.x += xx;
  center_.y += yy;
}

void Circle::printInf() const
{
  std::cout << "Parameters of circle:" << std::endl
    << "Position of the center: (" << center_.x << ";" << center_.y << ")" << std::endl
    << "Radius of the circle: " << radius_ << std::endl
    << "Area of the circle: " << getArea() << std::endl
    << "Parameters of frame rect of circle:" << std::endl
    << "Position of the frame rect: (" << getFrameRect().position.x << ";"
    << getFrameRect().position.y << ")" << std::endl
    << "Width of the frame rect: " << getFrameRect().width << std::endl
    << "Height of the frame rect: " << getFrameRect().height << std::endl << std::endl;
}


