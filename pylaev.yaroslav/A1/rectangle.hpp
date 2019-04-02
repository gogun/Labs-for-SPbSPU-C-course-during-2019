#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle:
    public Shape {
public:
  Rectangle(point_t const &center,
      double width, double height);

  double getWidth() const;
  double getHeight() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printSpec() const override;

private:
  double width_;
  double height_;
};

#endif
