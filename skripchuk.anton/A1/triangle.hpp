#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

struct Triangle: public Shape
{
public:
  Triangle(const point_t & pointA, const point_t & pointB, const point_t & pointC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & point) override;
  void move(double dx, double dy) override;
  void show() const override;

private:
  point_t pointA_;
  point_t pointB_;
  point_t pointC_;
  point_t center_;
};

#endif
