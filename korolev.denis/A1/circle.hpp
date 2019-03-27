#ifndef A1_CIRCLE_H
#define A1_CIRCLE_H

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &center, double radius);
  Circle(double x, double y, double radius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &position) override;
  void move(double xx, double yy) override;
  void printInf() const override;

private:
  point_t center_;
  double radius_;
};

#endif //A1_CIRCLE_H

