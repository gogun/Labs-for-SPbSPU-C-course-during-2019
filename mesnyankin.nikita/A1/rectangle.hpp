#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape {

public:
  Rectangle(double, double, point_t);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double, double) override;
  void move(point_t) override;
  double getWidth();
  double getHeight();
  point_t getPos();
  void showData();

private:
  double width_;
  double height_;
  point_t pos_;

};

#endif
