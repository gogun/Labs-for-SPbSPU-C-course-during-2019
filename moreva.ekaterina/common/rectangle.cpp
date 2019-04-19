#include "rectangle.hpp"
#include <iostream>

moreva::Rectangle::Rectangle(const point_t & pos, double width, double height) :
  center_(pos),
  width_(width),
  height_(height)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Width and height of the rectangle must be positive.");
  }
}

moreva::Rectangle::Rectangle(double posX, double posY, double width, double height) :
  Rectangle({posX, posY}, width, height)
{}

double moreva::Rectangle::getArea() const
{
  return width_ * height_;
}

moreva::rectangle_t moreva::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void moreva::Rectangle::move(const point_t & pos)
{
  center_ = pos;
}

void moreva::Rectangle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void moreva::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scaling factor must be positive.");
  }
  else
  {
    width_ *= factor;
    height_ *= factor;
  }
}

moreva::point_t moreva::Rectangle::getCenter() const
{
  return center_;
}

double moreva::Rectangle::getWidth() const
{
  return width_;
}

double moreva::Rectangle::getHeight() const
{
  return height_;
}

void moreva::Rectangle::printInfo() const
{
  std::cout << "Rectangle. Center is at (" << center_.x << ";" << center_.y << ")"
            << std::endl << "Width is: " << width_
            << std::endl << "Height is: " << height_
            << std::endl << "Area is: " << getArea()
            << std::endl << std::endl;
}


