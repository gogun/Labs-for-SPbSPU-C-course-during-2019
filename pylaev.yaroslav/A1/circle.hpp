#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle:
    public Shape {
public:
  Circle(const point_t &center,
      double radius);

  double getRadius() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printSpec() const override;

private:
  double radius_;
};

#endif
