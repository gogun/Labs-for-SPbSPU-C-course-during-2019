#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"

namespace gusarov
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &, const double);
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const double, const double) override;
    void move(const point_t &) override;
    void printInfo() const override;
    void scale(const double) override;
    double getRadius() const;
    void rotate(double) override;
  private:
    point_t center_;
    double radius_;
  };
}
#endif
