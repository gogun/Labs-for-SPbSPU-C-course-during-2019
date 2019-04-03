#include "circle.hpp"
#include <iostream>
#include <cassert>

const double PI = 3.14159265;

Circle::Circle(const point_t &pos, const double &radius) :
  pos_(pos),
  radius_(radius)
{
  assert((radius > 0));
  std::cout << "Circle was created\n\n";
}

double Circle::getArea()const
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { pos_, 2 * radius_, 2 * radius_ };
}

void Circle::printInfo() const
{
  rectangle_t framingRect = getFrameRect();
  std::cout << "Information about circle: \n" << "Radius: " << radius_ << "\n"
            << "Area: " << getArea() << "\n\n"
            << "Circle is at: { " << "x: " << pos_.x << ", y: " << pos_.y << " }\n\n"
            << "Information about framing rectangle:\n" << "Width:" << framingRect.width << "\n"
            << "Height: " << framingRect.height << "\n" << "Center : { " << "x: " << framingRect.pos.x
            << ", y: " << framingRect.pos.y << " }\n\n";
}

void Circle::move(const double &dx, const double &dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t &pos)
{
  pos_ = pos;
}
