#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

naumov::Circle::Circle(const point_t & centre, double radius) :
  Shape(centre),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Invalid circle's parameter");
  }
}

double naumov::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

naumov::rectangle_t naumov::Circle::getFrameRect() const
{
  rectangle_t frameRect = { 2 * radius_, 2 * radius_ , centre_, };
  return frameRect;
}

void naumov::Circle::move(const point_t & newCentre)
{
  centre_ = newCentre;
}

void naumov::Circle::move(double dX, double dY)
{
  centre_.x += dX;
  centre_.y += dY;
}

void naumov::Circle::setRadius(double newRadius)
{
  radius_ = newRadius;
}

void naumov::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient");
  }
  radius_ *= coefficient;
}

void naumov::Circle::getInformation()
{
  std::cout << "circle's frame rect: w " << this->getFrameRect().width
    << " h " << this->getFrameRect().height << std::endl;
  std::cout << "circle's centre: x " << this->getCentre().x
    << " y " << this->getCentre().y << std::endl;
  std::cout << "circle's area " << this->getArea() << std::endl << std::endl;
}
