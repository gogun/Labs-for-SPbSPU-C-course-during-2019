#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape {
public:
  Rectangle(point_t position, double width, double height);
  Rectangle(double x, double y, double width, double height);
  Rectangle(point_t position, double side);
  Rectangle(double x, double y, double side);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;

private:
  point_t center_;
  double width_;
  double height_;
};

#endif
