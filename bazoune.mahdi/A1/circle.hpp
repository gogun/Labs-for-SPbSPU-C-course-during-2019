#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double r, const point_t& Center);
  //void print() const override;
  double getArea() const override;
  point_t move(const point_t& point) override;
  point_t move(double dx, double dy) override;
  rectangle_t getFrameRect() const override;
private:
  double r_;
  point_t center_;
};

#endif
