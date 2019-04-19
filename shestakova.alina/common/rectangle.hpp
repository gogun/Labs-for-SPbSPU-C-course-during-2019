#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace shestakova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t pos, double w, double h);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;

  private:
    point_t pos_;
    double width_;
    double height_;
  };
}
#endif
