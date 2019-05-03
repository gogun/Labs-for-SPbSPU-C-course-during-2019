#ifndef CIRCLE
#define CIRCLE

#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t& pos, double r);
  Circle(double x, double y, double r);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;
  void show() const override;

private:
  point_t centre_;
  double radius_;
};

#endif
