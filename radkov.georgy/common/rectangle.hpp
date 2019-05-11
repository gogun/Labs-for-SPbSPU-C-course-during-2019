#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace radkov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &pos, double width, double height);
    double getWidth() const noexcept;
    double getHeight() const noexcept;
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(double dx, double dy) noexcept override;
    void move(const point_t &pos) noexcept override;
    void scale(double k) override;

  private:
    point_t points_[4];
    double width_, height_;
  };
}

#endif
