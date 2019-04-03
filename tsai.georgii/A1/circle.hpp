#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, const double &radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printInfo() const override;

  void move(const double &dx, const double &dy) override;
  void move(const point_t &pos) override;

private:
  double radius_;
  point_t pos_;
};

#endif
