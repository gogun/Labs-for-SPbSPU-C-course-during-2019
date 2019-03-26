#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
private:
  double width_;
  double height_;
  point_t center_;
public:
  Rectangle(const point_t &, double, double);
  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void move(double shiftX, double shiftY) override;
  void move(point_t newPoint) override;
  void printInfo();
};

#endif
