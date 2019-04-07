#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, const double &radius);
  Circle(const double &x, const double &y, const double &radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printFeatures() const override;

private:
  double radius_;
};

#endif
