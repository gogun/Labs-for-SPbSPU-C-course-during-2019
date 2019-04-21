#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace radkov
{
  class Circle:
    public Shape
  {
  public:
    Circle(const point_t &pos, double radius);
    double getRadius() const noexcept;
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(double dx, double dy) noexcept override;
    void move(const point_t &pos) noexcept override;
    void scale(double k) override;

  private:
    point_t pos_;
    double radius_;
  };
}

#endif
