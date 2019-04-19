#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &pos) override;
  void move(const double dx, const double dy) override;
  void writeParameters() const override;

private:
  point_t pos_;
  point_t point1_;
  point_t point2_;
  point_t point3_;
};

#endif
