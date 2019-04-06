#include "rectangle.hpp"
#include <iostream>
using namespace std;

Rectangle::Rectangle(const point_t &pos, const double width, const double height) :
  Shape(pos),
  width_(width),
  height_(height)
{
}

double Rectangle::getArea()
{
  return width_ * height_;
}

const rectangle_t Rectangle::getFrameRect()
{
  rectangle_t cur = { width_, height_, pos_};
  return cur;
}

void Rectangle::move(const point_t &NewCentre)
{
  pos_ = NewCentre;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::print()
{
  std:: cout << "Rectangle with the center ( " << pos_.x << pos_.y << " ) , Width = " << width_ << " , Height = " << height_ << endl;
}
