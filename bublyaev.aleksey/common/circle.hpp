#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

namespace bublyaev
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    double getRadius() const;
    void move(const point_t &newPos) override;
    void move(double dx, double dy) override;
    void scale(double multiplier) override;
    void printInfo() const override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif // CIRCLE_H
