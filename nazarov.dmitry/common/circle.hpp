#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include "shape.hpp"

namespace nazarov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &pos, const double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printFeatures() const override;
    void scale(double times) override;
    void move(double dx, double dy) override;
    void move(const point_t &pos) override;

  private:
    point_t pos_;
    double radius_;
  };
}
#endif
