#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t &, const double, const double);
  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void move(const double, const double) override;
  void move(const point_t &) override;
  void printInfo() const override;
private:
  double width_;
  double height_;
  point_t center_;
};

#endif
