#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle: public Shape {

public:
  Rectangle(double width, double height, const point_t &pos);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double x, double y) override;
  void move(const point_t &point) override;
  double getWidth();
  double getHeight();
  point_t getPos();

private:
  double width_;
  double height_;
  point_t pos_;

};

#endif
