#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace neupokoev
{
  class Triangle : public Shape
  {
  public:
    Triangle(const point_t &cornerA, const point_t &cornerB, const point_t &cornerC);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(const double dx, const double dy) override;
    void writeParameters() const override;
    void scale(double scaleFactor) override;

  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}

#endif
