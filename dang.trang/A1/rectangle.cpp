#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t &center) :
  width_(width),
  height_(height),
  pos_(center)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(double mX, double mY)
{
  pos_.x += mX;
  pos_.y += mY;
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void Rectangle::printInfo() const
{
	std::cout << "area_of_rectangle_=" << getArea()
			  << "\n Width:  " << width_
		      << "\n Height: " << height_
			  << "\n position_X_Y_" << pos_.x << " " << pos_.y << std::endl;
}



