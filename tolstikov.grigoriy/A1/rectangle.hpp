#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape {
public:
  Rectangle(point_t pos, double width, double height);
  Rectangle(point_t pos, double width); // Square

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  point_t pos_;
  double width_;
  double height_;
};

#endif
