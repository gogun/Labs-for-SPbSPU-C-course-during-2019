#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t &pos, const double height, const double width) :
    rect_{pos, width, height}
{
  if (height <= 0) {
    std::cerr << "Height less or equal zero" << std::endl;
  }
  if (width <= 0) {
    std::cerr << "Width less or equal zero" << std::endl;
  }
};

double Rectangle::getArea() const
{
  return rect_.height * rect_.width;
};

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
};

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
};

void Rectangle::move(const point_t &point)
{
  rect_.pos = point;
};

point_t Rectangle::getCenter() const
{
  return rect_.pos;
};

Rectangle::~Rectangle()
{
  std::cout << "Rectangle was delete" << std::endl;
};