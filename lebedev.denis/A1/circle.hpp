#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(point_t &pos, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double x, const double y) override;
  void move(point_t &new_poit) override;

private:
  point_t m_pos;
  double m_radius;
};
#endif
