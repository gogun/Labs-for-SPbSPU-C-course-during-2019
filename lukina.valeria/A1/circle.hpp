#ifndef CircleHPP
#define CircleHPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double r, point_t c);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t NewPoint) override;

private:
  double radius_;
  point_t center_;
};

#endif
