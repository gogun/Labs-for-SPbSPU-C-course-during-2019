#ifndef TriangleHPP_A2
#define TriangleHPP_A2
#include "shape.hpp"

namespace sheve
{
  class Triangle : public Shape
  {
  public:
    Triangle(const point_t &p1, const point_t &p2, const point_t &p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &p) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void printInfo() const override;

  private:
    point_t center_;
    point_t pointA_;
    point_t pointB_;
    point_t pointC_;
  };
}

#endif
