#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include "iostream"

namespace krasnopyorov
{
  class Circle: public Shape
  {
  public:
    Circle(double radius, point_t dot);
    void move(double deltax, double deltay) override;
    void move(const point_t &dot) override;
    void scale(double k) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    double getRadius() const;
    void writeChanges() const;

  private:
    point_t centre_;
    double r_;
  };
}


#endif
