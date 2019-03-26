#ifndef A1_RECTANGLE_H
#define A1_RECTANGLE_H

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &position, double width, double height);
  Rectangle(double x, double y, double width, double height);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &position) override;
  void move(double xx, double yy) override;
  void printInf() const;

private:
  double width_, height_;
  point_t position_;
};

#endif //A1_RECTANGLE_H
