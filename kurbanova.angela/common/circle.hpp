#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace kurbanova
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, double rad);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t &pos1) override;
    void printInfo() const override;
    void scale(double coefficient) override;
    point_t getCenter() const;
    double getRad() const;

  private:
    point_t pos_;
    double radius_;
  };
}

#endif // !CIRCLE_HPP
