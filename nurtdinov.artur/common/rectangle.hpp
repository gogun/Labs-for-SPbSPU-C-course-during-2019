#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"

namespace nurtdinov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &point, double width, double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    void scale(double ratio) override;

  private:
    point_t position_;
    double width_;
    double height_;
  };
}

#endif //A1_RECTANGLE_HPP
