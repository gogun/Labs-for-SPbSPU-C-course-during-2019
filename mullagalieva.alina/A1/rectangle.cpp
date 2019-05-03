#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t& position, double width, double height) :
  centre_(position),
  width_(width),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

Rectangle::Rectangle(double x, double y, double width, double height) :
  centre_({x, y}),
  width_(width),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, centre_};
}

void Rectangle::move(const point_t& point)
{
  centre_ = point;
}

void Rectangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void Rectangle::show() const
{
  std::cout << "Rectangle" << "\n";
  std::cout << "Position of the figure: ("
      << centre_.x << "; " << centre_.y << ")" << "\n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle centre: ("
      << getFrameRect().pos.x << "; " << getFrameRect().pos.y << ")" << "\n";
  std::cout << "Frame Rectangle width: " << getFrameRect().width << "\n";
  std::cout << "Frame Rectangle height: " << getFrameRect().height << "\n";
}
