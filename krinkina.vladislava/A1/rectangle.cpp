#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &centre, double width, double height) :
  centre_(centre),
  width_(width),
  height_(height)
{
  assert((width > 0.0) && (height > 0.0));
}

void Rectangle::move(const point_t &centre)
{
  centre_ = centre;
}

void Rectangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t
  {
    width_,
    height_,
    centre_
  };
}

void Rectangle::printInfo() const
{
  std::cout << "coordinates of the centre (" << centre_.x << "," << centre_.y << ")\n";
  std::cout << "widht = " << width_ << ", height = " << height_ << '\n';
  std::cout << "area =" << Rectangle::getArea() << '\n';
  rectangle_t rectagle = getFrameRect();
  std::cout << "parameters FrameRect:\n";
  std::cout << "widht = " << rectagle.width << ", height = " << rectagle.height << '\n';
  std::cout << "coordinates of the centre (" << rectagle.pos.x << "," << rectagle.pos.y << ")\n";
}
