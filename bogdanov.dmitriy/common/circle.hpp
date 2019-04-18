#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace bogdanov {

class Circle: public Shape
{
public:
  Circle(const point_t &center, double radius);

  void move(const point_t &newCenter) override;
  void move(double dx, double dy) override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void writeInfo() const override;
  void scale(double scalingFactor) override;

private:
  double radius_;
  point_t center_;
};

} // namespace bogdanov

#endif
