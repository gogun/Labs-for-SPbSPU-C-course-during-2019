#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &position, double width, double height);

  rectangle_t getFrameRect() const;
  double getArea() const;

  void printInfo() const;

private:
  double width_, height_;
};

#endif //RECTANGLE_HPP
