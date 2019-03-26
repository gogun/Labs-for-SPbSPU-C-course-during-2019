#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, const point_t &centre);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t &point) override;

private:
  rectangle_t parameters_;
};

#endif
