#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t pos, double width, double height):
  rectCl_(rectangle_t{pos, width, height})
{
  assert((width > 0.0) && (height > 0.0));
}
Rectangle::Rectangle(double x, double y, double width, double height):
  Rectangle(point_t{x, y}, width, height)
{
}

double Rectangle::getArea() const
{
  return rectCl_.height * rectCl_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectCl_;
}

void Rectangle::move(const point_t newPos)
{
  rectCl_.pos = newPos;
}

void Rectangle::move(double newX, double newY)
{
  rectCl_.pos = point_t{rectCl_.pos.x + newX, rectCl_.pos.y + newY};
}

point_t Rectangle::getPosition() const
{
  return rectCl_.pos;
}

double Rectangle::getHeight() const
{
  return rectCl_.height;
}

double Rectangle::getWidth() const
{
  return rectCl_.width;
}


void Rectangle::print() const
{
  std::cout << "Here is rectangle. Width = " << rectCl_.width << ", height = " << rectCl_.height << ".\n";
  std::cout << "Coordinates of centre: (" << rectCl_.pos.x << ", " << rectCl_.pos.y << "), ";
  std::cout << "its area = " << getArea() << "\n";
  std::cout << "Frame of rectangle: centre coordinates (" << getFrameRect().pos.x << ", ";
  std::cout << getFrameRect().pos.y << "), width = " << getFrameRect().width;
  std::cout << ", height = " << getFrameRect().height << ". \n\n";
}
