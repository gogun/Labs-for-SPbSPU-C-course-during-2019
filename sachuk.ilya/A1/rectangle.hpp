#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
class Rectangle:public Shape{
public:
  Rectangle(point_t point, double w, double h);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double xx, double yy) override;
  void printInfo() const override;

private:
  point_t center_;
  double width_;
  double height_;
};

#endif //RECTANGLE_HPP
