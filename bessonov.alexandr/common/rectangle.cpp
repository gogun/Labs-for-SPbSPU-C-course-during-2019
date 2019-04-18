#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

bessonov::Rectangle::Rectangle(const bessonov::point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
	if (width <= 0)
	{
		throw std::invalid_argument("Problematic width");
	}
	if (height <= 0)
	{
		throw std::invalid_argument("Problematic height");
	}
}

double bessonov::Rectangle::getArea() const
{
  return width_ * height_;
}

bessonov::rectangle_t bessonov::Rectangle::getFrameRect() const
{
  return { width_, height_, center_ };
}

void bessonov::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void bessonov::Rectangle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void bessonov::Rectangle::scale(double factor)
{
	if (factor <= 0)
	{
		throw std::invalid_argument("Problematic factor");
	}
	width_ *= factor;
	height_ *= factor;
}
