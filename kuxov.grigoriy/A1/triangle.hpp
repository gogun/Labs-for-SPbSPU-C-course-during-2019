#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t & vA, const point_t & vB, const point_t & vC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print() const override;
  void move(double dx, double dy) override;
  void move(const point_t & nPos) override;

private:
  point_t pos_;
  point_t vA_;
  point_t vB_;
  point_t vC_;
};

#endif