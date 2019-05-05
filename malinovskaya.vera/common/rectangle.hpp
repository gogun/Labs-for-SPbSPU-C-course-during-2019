#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace malinovskaya
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const rectangle_t& rectangle);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t& point) override;
    void print() const override;
    void scale(double coeff) override;
  private:
    rectangle_t rectangle_;
  };
}

#endif
