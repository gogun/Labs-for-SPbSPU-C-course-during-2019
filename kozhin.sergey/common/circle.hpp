#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace kozhin
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t&, double);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const override;
    void move(double x, double y) override;
    void move(const point_t&) override;
    void scale(double) override;

  private:
    point_t center_;
    double radius_;
  };
} // namespace kozhin

#endif // CIRCLE_HPP
