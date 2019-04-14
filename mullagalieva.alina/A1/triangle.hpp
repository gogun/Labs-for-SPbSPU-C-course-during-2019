#ifndef TRIANGLE
#define TRIANGLE

#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t& pos, double side1, double side2, double side3);
  Triangle(double x, double y, double side1, double side2, double side3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;
  point_t getPos() const override;

private:
  point_t centre_;
  double side1_;
  double side2_;
  double side3_;
};

#endif
