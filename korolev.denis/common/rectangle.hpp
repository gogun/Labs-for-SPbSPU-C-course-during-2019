#ifndef A1_RECTANGLE_H
#define A1_RECTANGLE_H

#include "shape.hpp"

namespace korolev
{
  class Rectangle : public Shape {
  public:
    Rectangle(const point_t &center, double width, double height);
    Rectangle(double x, double y, double width, double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &position) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;

  private:
    point_t center_;
    double width_, height_;
  };
}
#endif //A1_RECTANGLE_H

