#include "circle.hpp"
#include <iostream>
#include <math.h>

bublyaev::Circle::Circle(const point_t &center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
}

double bublyaev::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

bublyaev::rectangle_t bublyaev::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

double bublyaev::Circle::getRadius() const
{
  return radius_;
}

void bublyaev::Circle::move(const point_t &newPos)
{
  center_ = newPos;
}

void bublyaev::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void bublyaev::Circle::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Invalid scale multiplier");
  }
  else
  {
    radius_ *= multiplier;
  }
}

void bublyaev::Circle::printInfo() const
{
  std::cout << "Circle: \nCenter coordinates: (" << center_.x << " , " << center_.y << ")" << std::endl;
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Frame: " << std::endl;
  std::cout << "Width: " << frame.width << std::endl;
  std::cout << "Height: " << frame.height << std::endl;
}
