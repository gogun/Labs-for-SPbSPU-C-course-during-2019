#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"

namespace chugaynov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &point, double radius);
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    double getRadius() const;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
  private:
    point_t pos_;
    double radius_;
  };
}
#endif
