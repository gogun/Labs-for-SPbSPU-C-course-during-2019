#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &ptA, const point_t &ptB, const point_t &ptC);
  void setPoints(const point_t &ptA, const point_t &ptB, const point_t &ptC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t move(const point_t &point) override;
  point_t move(double dx, double dy) override;
  void print() const override;
private:
  point_t pos_;
  point_t A_;
  point_t B_;
  point_t C_;
  static double getMin(const double &ptA, const double &ptB, const double &ptC);
  static double getMax(const double &ptA, const double &ptB, const double &ptC);
};
#endif
