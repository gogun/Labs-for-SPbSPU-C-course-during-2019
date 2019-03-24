#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double r, const point_t &position);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &p) override;
  point_t Center() const override;
  void print() const override;

private:
  double r_;
  point_t pos_;
};

#endif /* CIRCLE_HPP */
