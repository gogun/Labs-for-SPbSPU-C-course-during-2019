#include "Rectangle.hpp"
#include <stdexcept>
#include <iostream>

Rectangle::Rectangle(const point_t &place, const double width, const double height):
  Shape(place),
  width_(width),
  height_(height)
{
  if (width <= 0) 
  {
    throw std::invalid_argument("negative width");
  };
  if (height <= 0) 
  {
    throw std::invalid_argument("negative height");
  };
};

double Rectangle::getArea() const
{
  return width_ * height_;
};

rectangle_t Rectangle::getFrameRect() const
{
  return{ place_, width_, height_ };
};

void Rectangle::getInfo() const
{
  std::cout << "Placement of the rectangle: " << place_.x << " " << place_.y << "\n";
  std::cout << "Width: " << width_ << "\n";
  std::cout << "Height: " << height_ << "\n";
};

point_t Rectangle::getPlace() const
{
  return(place_);
};

double Rectangle::getWidth() const
{
  return(width_);
}

double Rectangle::getHeight() const
{
  return(height_);
}

void Rectangle::scale(const double scoping)
{
  if (scoping <= 0)
  {
    throw std::invalid_argument("negative scoping");
  }
  else 
  {
    width_ = width_ * scoping;
    height_ = height_ * scoping;
  }
};
