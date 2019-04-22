#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <math.h>
#include <cassert>
#include <iostream>

krinkina::Circle::Circle(const point_t &centre, double radius) :
  centre_(centre),
  radius_(radius)
{
  if (radius_ <= 0) 
  {
    throw std::invalid_argument("radius  must be greater than 0 ");
  }
}

double krinkina::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

krinkina::rectangle_t krinkina::Circle::getFrameRect() const
{
  return rectangle_t
  {
    2 * radius_,
    2 * radius_,
    centre_
  };
}

void krinkina::Circle::move(const point_t &centre)
{
  centre_ = centre;
}

void krinkina::Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void krinkina::Circle::scale(double coefficient)
{
  if (coefficient <= 0) 
  {
    throw std::invalid_argument("Coefficient must be positive ");
  }
  radius_ *= coefficient;
}

double krinkina::Circle::getRadius() const
{
  return radius_;
}

void krinkina::Circle::printInfo() const
{
  std::cout << "The coordinates of the centre (" << centre_.x << "," << centre_.y << ")\n";
  std::cout << "radius = " << radius_ << '\n';
  std::cout << "area = " << Circle::getArea() << '\n';
  rectangle_t rectagle = getFrameRect();
  std::cout << "parameters FrameRect:\n";
  std::cout << "height = " << rectagle.height << ", width =" << rectagle.width << '\n';
  std::cout << "coordinates of the centre: (" << rectagle.pos.x << "," << rectagle.pos.y << ")\n";
}
