#ifndef A2_RECTANGLE_HPP
#define A2_RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace andreeva
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &point, double width, double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t &point) override;
    void scale(double factor) override;

  private:
    point_t center_;
    double width_;
    double height_;
  };
}
#endif
