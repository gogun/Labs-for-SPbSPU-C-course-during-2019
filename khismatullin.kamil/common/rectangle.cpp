#include "rectangle.hpp"
#include <iostream>

khismatullin::Rectangle::Rectangle(const point_t &pos, const double height, const double width) :
    rect_{pos, width, height}
{
  if (height <= 0)
  {
    throw std::invalid_argument("Height should be > 0");
  }
  if (width <= 0)
  {
    throw std::invalid_argument("Width should be > 0");
  }
}

double khismatullin::Rectangle::getArea() const
{
  return rect_.height * rect_.width;
}

khismatullin::rectangle_t khismatullin::Rectangle::getFrameRect() const
{
  return rect_;
}

void khismatullin::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void khismatullin::Rectangle::move(const point_t &point)
{
  rect_.pos = point;
}

khismatullin::point_t khismatullin::Rectangle::getCenter() const
{
  return rect_.pos;
}

void khismatullin::Rectangle::show() const
{
  std::cout << "[Rectangle]: \n";
  std::cout << "Center : (" << getCenter().x << ", " << getCenter().y << ")\n";
  std::cout << "Height : " << getFrameRect().height << "\n";
  std::cout << "Width  : " << getFrameRect().width << "\n";
  std::cout << "Area   : " << getArea() << "\n";
}

void khismatullin::Rectangle::scale(const double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Multiplier of scale should be > 0");
  }
  rect_.height *= multiplier;
  rect_.width *= multiplier;
}
