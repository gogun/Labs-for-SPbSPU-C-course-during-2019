#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"


namespace sheve
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &p) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void printInfo() const override;

  private:
    point_t m_pos;
    double m_radius;
  };
}

#endif
