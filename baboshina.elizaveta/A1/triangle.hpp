#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t pointA, const point_t pointB, const point_t pointC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t point) override;
  void move(const double x, const double y) override;
  void getInfo() const;
private:
  point_t pointA_;
  point_t pointB_;
  point_t pointC_;
  double getMax(double const first, double const second, double const third) const;
  double getMin(double const first, double const second, double const third) const;
};

#endif // !TRIANGLE_HPP
