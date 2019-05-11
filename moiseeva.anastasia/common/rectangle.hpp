#ifndef A2_RECTANGLE_HPP
#define A2_RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace moiseeva
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &dot, double width, double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t &point) override;
    void scale(double coefficient) override;

  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif //A2_RECTANGLE_HPP
