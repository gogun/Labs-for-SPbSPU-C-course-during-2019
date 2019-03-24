//
//  circle.cpp
//  A1
//
//  Created by Ирина on 23.03.2019.
//  Copyright © 2019 Ирина. All rights reserved.
//

#include "circle.hpp"

#include <iostream>
#include <stdexcept>

#define Pi 3.141592653589

Circle::Circle(double r, const point_t&position):
  r_(r),
  pos_(position)
{
  if (r_ <= 0)
  {
   throw std::invalid_argument("Invalid circle radius");
  }
}
double Circle::getArea() const
{
  return Pi*r_*r_;
}
rectangle_t Circle:: getFrameRect() const
{
  return {2 * r_, 2 * r_, pos_};
}
point_t Circle::Center() const
{
  return pos_;
}
void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
void Circle::move(const point_t &p)
{
  pos_ = p;
}
void Circle::print() const
{
  std::cout << "Area of circle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << getFrameRect().width_<< std::endl;
  std::cout << "Height of frame rectangle: " << getFrameRect().height_<< std::endl;
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos_.x
            << "; " << getFrameRect().pos_.y << ")" << std::endl;
}
