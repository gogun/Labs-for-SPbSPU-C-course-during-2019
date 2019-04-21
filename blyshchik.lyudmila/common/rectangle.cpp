#include "rectangle.hpp"
#include <iostream>
#include <cassert>

blyshchik::Rectangle::Rectangle(const point_t pos, double width, double height):
  rectCl_(rectangle_t{pos, width, height})
{
  if ((width <= 0.0) || (height <= 0.0)) {
    throw std::invalid_argument("Width and height must be positive numbers. ");
  }
}

blyshchik::Rectangle::Rectangle(double x, double y, double width, double height):
  Rectangle(point_t{x, y}, width, height)
{
}

double blyshchik::Rectangle::getArea() const
{
  return rectCl_.height * rectCl_.width;
}

rectangle_t blyshchik::Rectangle::getFrameRect() const
{
  return rectCl_;
}

void blyshchik::Rectangle::move(const point_t newPos)
{
  rectCl_.pos = newPos;
}

void blyshchik::Rectangle::move(double newX, double newY)
{
  rectCl_.pos.x += newX;
  rectCl_.pos.y += newY;
}

point_t blyshchik::Rectangle::getPosition() const
{
  return rectCl_.pos;
}

double blyshchik::Rectangle::getHeight() const
{
  return rectCl_.height;
}

double blyshchik::Rectangle::getWidth() const
{
  return rectCl_.width;
}

void blyshchik::Rectangle::print() const
{
  std::cout << "Here is rectangle. Width = " << rectCl_.width << ", height = " << rectCl_.height << ".\n";
  std::cout << "Coordinates of centre: (" << rectCl_.pos.x << ", " << rectCl_.pos.y << "), ";
  std::cout << "its area = " << getArea() << "\n";
  std::cout << "Frame of rectangle: centre coordinates (" << getFrameRect().pos.x << ", ";
  std::cout << getFrameRect().pos.y << "), width = " << getFrameRect().width;
  std::cout << ", height = " << getFrameRect().height << ". \n\n";
}

void blyshchik::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0.0) {
    throw std::invalid_argument("Coefficient must be positive number. ");
  }
  rectCl.width_ *= coefficient;
  rectCl.height_ *= coefficient;
}
