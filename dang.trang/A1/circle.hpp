#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(double Rcircle, const point_t &cpoint);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double mX, double mY);
  void move(const point_t &point);
  void dataoutput() const;

private:
  double cR_;
  point_t pos_;
};

#endif
