#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Triangle : public Shape
{
  public:
    Triangle(point_t pA, point_t pB, point_t pC);
    double getArea() const override;
    rectangle_t getFrameRect() const override;

  private:
    point_t pointA_;
    point_t pointB_;
    point_t pointC_;
    double lengthA_;
    double lengthB_;
    double lengthC_;
    double getLength(point_t a, point_t b);
    void assertTriangle(double a, double b, double c);
};

#endif
