#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

nazarov::Circle::Circle(const point_t &pos, const double &radius) :
  pos_(pos),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius must be more than 0");
  }
}


double nazarov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

nazarov::rectangle_t nazarov::Circle::getFrameRect() const
{
  return { pos_, 2 * radius_, 2 * radius_ };
}

nazarov::point_t nazarov::Circle::getPos() const
{
  return pos_;
}

double nazarov::Circle::getRadius() const
{
  return radius_;
}

void nazarov::Circle::printFeatures() const
{
  rectangle_t framingRectangle = getFrameRect();
  std::cout << "Circle information: \n" << "Radius: " << radius_ << "\n"
            << "Area: " << getArea() << "\n\n"
            << "Circle is at point: { " << "x: " << pos_.x << ", y: " << pos_.y << " }\n\n"
            << "Information about framing rectangle:\n" << "Width:" << framingRectangle.width << "\n"
            << "Height: " << framingRectangle.height << "\n" << "Center : { " << "x: " << framingRectangle.pos.x
            << ", y: " << framingRectangle.pos.y << " }\n\n";
}

void nazarov::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void nazarov::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void nazarov::Circle::scale(double times)
{
  if (times <= 0)
  {
    throw std::invalid_argument("Enter times correctly");
  }
  else
  {
    radius_ *= times;
  }
}
