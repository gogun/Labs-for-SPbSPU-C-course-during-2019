#ifndef CRICLE_H
#define CIRCLE_H
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, double r);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(double dx, double dy) override;
  void getInfo() const override;
  void scale(double cScaling) override;

private:
  point_t center_;
  double radius_;
};
#endif
