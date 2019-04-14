#ifndef A1_TRIANGLE_HPP
#define A1_TRIANGLE_HPP
#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(point_t point1, point_t point2, point_t point3);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;

private:
  point_t point1_;
  point_t point2_;
  point_t point3_;
  point_t pos_;
};

#endif //A1_TRIANGLE_HPP
