#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace gusarov
{
  class Triangle: public Shape
  {
  public:
    Triangle(const point_t &, const point_t &, const point_t &);
    point_t getCenter() const;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double, const double) override;
    void move(const point_t &) override;
    void scale(const double) override;
    void printInfo() const override;
    void rotate(double) override;
  private:
    point_t pointA_;
    point_t pointB_;
    point_t pointC_;
  };
}

#endif
