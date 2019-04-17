#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const point_t &pos, const double sideA, const double sideB, const double sideC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &pos) override;
  void move(const double dx, const double dy) override;
  void writeParameters() const override;

private:
  point_t pos_;
  double sideA_;
  double sideB_;
  double sideC_;
};

#endif
