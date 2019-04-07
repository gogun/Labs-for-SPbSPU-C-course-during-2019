#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape {
public:
  Rectangle(double width, double height, point_t pos);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
