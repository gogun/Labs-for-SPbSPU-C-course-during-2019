#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace ivanenko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double width, double height, const point_t &pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    void scale(double scale) override;

  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif //RECTANGLE_HPP

