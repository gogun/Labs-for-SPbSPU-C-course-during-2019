#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double height, double width, const point_t &center);
  double getArea() const override;
  void move(double dx, double dy) override;
  void move(const point_t &center) override;
  rectangle_t getFrameRect() const override;
  void showPoint() const override;
private:
  double height_;
  double width_;
  point_t pos_;
};

#endif
