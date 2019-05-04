#ifndef TRIANGLE
#define TRIANGLE

#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t& posA, const point_t& posB, const point_t& posC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;
  void show() const override;

private:
  point_t centre_;
  point_t posA_;
  point_t posB_;
  point_t posC_;
};

#endif
