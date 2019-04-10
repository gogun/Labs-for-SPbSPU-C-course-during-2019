#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const triangle_t &parameters);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &pos) override;
  void move(double dx, double dy) override;
  void writeParameters() const override;

private:
  triangle_t triangle_;
};

#endif
