#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const point_t& pos, double radius) :
  centre_(pos),
  radius_(radius)
{
  assert(radius_ >= 0.0);
}

Circle::Circle(double x, double y, double radius) :
  centre_({x, y}),
  radius_(radius)
{
  assert(radius_ >= 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, centre_};
}

void Circle::move(const point_t& point)
{
  centre_ = point;
}

void Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void Circle::show() const
{
  std::cout << "Circle" << "\n";
  std::cout << "Position of the figure: ("
      << centre_.x << "; " << centre_.y << ")" << "\n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle centre: ("
      << getFrameRect().pos.x << "; " << getFrameRect().pos.y << ")" << "\n";
  std::cout << "Frame Rectangle width: " << getFrameRect().width << "\n";
  std::cout << "Frame Rectangle height: " << getFrameRect().height << "\n";
}
