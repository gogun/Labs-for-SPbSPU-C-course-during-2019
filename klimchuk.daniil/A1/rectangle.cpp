#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double width, double height, const point_t &center) :
  width_(width),
  height_(height),
  pos_(center)
{
  if (width <= 0) {
    std::cerr << "Invalid rectangle width. Width must be above zero.\n";
  }
  if (height <= 0) {
    std::cerr << "Invalid rectangle height. Height must be above zero.\n";
  }
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::printInfo() const
{
  std::cout << "Rectangle:"
      << "\n  Width: " << width_
        << "\n  Height: " << height_
          << "\n  Position:"
            << "\n    x: " << pos_.x
              << "\n    y: " << pos_.y
                << "\n  Area: " << this->getArea() << "\n\n";
}
