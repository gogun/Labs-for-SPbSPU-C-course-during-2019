#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle:
    public Shape
{
public:
  Circle(const double r, point_t p);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t newpos) override;
  void getInfo() const override;
private:
  double radius_;
  point_t pos_;
};

#endif // CIRCLE_HPP
