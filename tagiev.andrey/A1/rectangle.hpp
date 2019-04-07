#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.hpp"

class Rectangle: public Shape{
public:
  Rectangle(const point_t &, double, double);

  rectangle_t getFrameRect() const override;

  double getArea() const override;

  void move(double, double) override;

  void move(point_t) override;
private:
  point_t center_;
  double width_;
  double height_;
};

#endif
