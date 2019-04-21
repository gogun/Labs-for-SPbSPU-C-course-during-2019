#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace radkov
{
  class Triangle:
    public Shape
  {
  public:
    Triangle(const point_t &pos_a, const point_t &pos_b, const point_t &pos_c);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(double dx, double dy) noexcept override;
    void move(const point_t &pos) noexcept override;
    void scale(double k) override;

  private:
    point_t points_[3];
    point_t getCenter() const noexcept;
  };
}

#endif
