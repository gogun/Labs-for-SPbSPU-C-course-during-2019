#include "rectangle.hpp"
#include <iostream>

naumov::Rectangle::Rectangle(const point_t & centre, double width, double height) :
  Shape(centre),
  width_(width),
  height_(height)
{
  if ((width <= 0) || (height <= 0))
  {
    throw (char*) "Invalid rectangle's parameters";
  }
}

double naumov::Rectangle::getArea() const
{
  return width_ * height_;
}

naumov::rectangle_t naumov::Rectangle::getFrameRect() const
{
  rectangle_t frameRect{ width_, height_, centre_ };
  return frameRect;
}

void naumov::Rectangle::move(const point_t & newCentre)
{
  centre_ = newCentre;
}

void naumov::Rectangle::move(double dX, double dY)
{
  centre_.x += dX;
  centre_.y += dY;
}

void naumov::Rectangle::setWidth(double newWidth)
{
  width_ = newWidth;
}

void naumov::Rectangle::setHeight(double newHeight)
{
  height_ = newHeight;
}

void naumov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw (char*) "Invalid coefficient";
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

void naumov::Rectangle::getInformation()
{
  std::cout << "rectangle's frame rect: w " << this->getFrameRect().width
    << " h " << this->getFrameRect().height << std::endl;
  std::cout << "rectangle's centre: x " << this->getCentre().x
    << " y " << this->getCentre().y << std::endl;
  std::cout << "rectangle's area " << this->getArea() << std::endl << std::endl;
}
