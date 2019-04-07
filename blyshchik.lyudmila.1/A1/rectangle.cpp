#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t pos, double width, double height):
  rectCl_(rectangle_t{pos, width, height})
  {
    assert((width > 0.0) && (height > 0.0));
    std::cout << "Constructor with assert done. \n";
}
Rectangle::Rectangle(double locX, double locY, double width, double height):
  Rectangle(point_t{locX, locY}, width, height)
  {
    std::cout << "Constructor done. \n";
}

  double Rectangle::getArea() const
  {
    return getHeight() * getWidth();
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
    rectCl_.pos = point_t{getPosition().locX + newX, getPosition().locY + newY};
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
    std::cout << "Here is rectangle. Width = " << getWidth() << ", height = " << getHeight() << ".\n";
    std::cout << "Coordinates of centre: (" << getPosition().locX << ", " << getPosition().locY << "), ";
    std::cout << "its area = " << getArea() << "\n";
    std::cout << "Frame of rectangle: centre coordinates (" << getFrameRect().pos.locX << ", ";
    std::cout << getFrameRect().pos.locY << "), width = " << getFrameRect().width;
    std::cout << ", height = " << getFrameRect().height << ". \n\n";
  }
