#include "rectangle.hpp"
#include <iostream>

prohorova::Rectangle::Rectangle(const point_t &pos, double width, double height):
  rect_(rectangle_t{pos, width, height})
{
  if ((rect_.width <= 0) || (rect_.height <= 0))
  {
    throw std::invalid_argument("Parameters must be positive numbers.\n");
  }
}
prohorova::Rectangle::Rectangle(double posX, double posY, double width, double height):
  Rectangle(point_t{posX,posY}, width, height)
{
}
double prohorova::Rectangle::getArea() const
{
  return getHeight() * getWidth();
}
prohorova::rectangle_t prohorova::Rectangle::getFrameRect() const
{
  return rect_;
}
void prohorova::Rectangle::move(const point_t& newPos)
{
  rect_.pos = newPos;
}
void prohorova::Rectangle::move(double dx, double dy)
{
  rect_.pos = point_t{getPos().x + dx, getPos().y + dy};
}
void prohorova::Rectangle::show() const
{
  std::cout << "Rectangle. Width = " << getWidth() << ", height = " << getHeight();
  std::cout << ", position of centre = (" << getPos().x << " , " << getPos().y << "), ";
  std::cout << "area = " << getArea();
  rectangle_t frame = getFrameRect();
  std::cout << "\n\tFrame rectangle: centre(" << frame.pos.x << ", " << frame.pos.y << ")";
  std::cout << ", width = " << frame.width << ", height = " << frame.height << ".\n";
}
void prohorova::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Factor of scaling must be a positive number.\n");
  }
  rect_.width *= factor;
  rect_.height *= factor;
}
double prohorova::Rectangle::getWidth() const
{
  return rect_.width;
}
double prohorova::Rectangle::getHeight() const
{
  return rect_.height;
}
prohorova::point_t prohorova::Rectangle::getPos() const
{
  return rect_.pos;
}
