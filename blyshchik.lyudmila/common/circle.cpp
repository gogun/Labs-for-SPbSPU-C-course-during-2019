#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

blyshchik::Circle::Circle(const point_t locO, double radius):
  centre_(locO),
  radius_(radius)
{
  if (radius_ <= 0.0) {
    throw std::invalid_argument("Radius must be positive number. ");
  };
}

blyshchik::Circle::Circle(double x, double y, double radius):
  Circle(point_t{x, y}, radius)
{
}

double blyshchik::Circle::getArea() const
{
  return M_PI * pow(radius_, 2);
}

rectangle_t blyshchik::Circle::getFrameRect() const
{
  return {centre_, radius_ * 2, radius_ * 2};
}

void blyshchik::Circle::move(const point_t newCentre)
{
  centre_ = newCentre;
}

void blyshchik::Circle::move(double newX, double newY)
{
  centre_.x += newX;
  centre_.y += newY;
}

point_t blyshchik::Circle::getPosition() const
{
  return centre_;
}

double blyshchik::Circle::getRadius() const
{
  return radius_;
}

void blyshchik::Circle::print() const
{
  std::cout << "Here is circle. Radius = " << radius_ << ", coordinates of centre (";
  std::cout << centre_.x << ", " << centre_.y << "), its area = ";
  std::cout << getArea() << ".\n Frame of circle: centre coordinates (";
  std::cout << getFrameRect().pos.x << ", " << getFrameRect().pos.y << ", ";
  std::cout << "width = " << getFrameRect().width << ", height = " << getFrameRect().height << ". \n\n";
}

void blyshchik::Circle::scale(double coefficient)
{
  if (coefficient <= 0.0) {
    throw std::invalid_argument("Coefficient must be positive number. ");
  }
  radius_ *= coefficient;
}
