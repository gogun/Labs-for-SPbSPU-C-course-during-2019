#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &A, const point_t &B, const point_t &C);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &centre) override;
  void move(const double &dx, const double &dy) override;
  void printShapeInfo() const override;
private:
  point_t pointA_;
  point_t pointB_;
  point_t pointC_;
  static double getMin(const double &A, const double &B, const double &C);
  static double getMax(const double &A, const double &B, const double &C);
};
#endif
