#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t&, double, double, double);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double, double) override;
  void move(const point_t&) override;
  void printInfo() const override;

private:
  double getMedianLength(double, double, double) const;
  point_t center_;
  double side1_, side2_, side3_;
};

#endif // TRIANGLE_HPP
