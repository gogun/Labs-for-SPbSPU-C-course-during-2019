#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t& pos, double sideA, double sideB, double sideC);
  Triangle(double x, double y, double sideA, double sideB, double sideC);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getPos() const override;
  void move(const point_t& centre) override;
  void move(double deltaX, double deltaY) override;
private:
  point_t centre_;
  double sideA_;
  double sideB_;
  double sideC_;
};

#endif
