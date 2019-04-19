#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
namespace frolov
{
  class Triangle : public frolov::Shape
  {
  public:
    Triangle(const point_t &point0, const point_t &point1, const point_t &point3);
    void move(double dx, double dy) override;
    void move(const point_t &center) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void showPoint() const override;
    void scale(double factor) override;
  private:
    point_t point0_;
    point_t point1_;
    point_t point2_;
    point_t center_;
  };
}

#endif
