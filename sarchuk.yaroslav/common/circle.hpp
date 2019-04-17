#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
namespace sarchuk
{
  class Circle : public Shape
  {
  public:
    Circle(point_t, double);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void writeInfo() const override;
    void move(point_t) override;
    void move(double, double) override;
    void scale(double) override;

  private:
    point_t pos_;
    double radius_;
  };
}
#endif
