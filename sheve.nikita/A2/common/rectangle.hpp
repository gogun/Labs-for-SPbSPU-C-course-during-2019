#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace sheve
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &center, double width, double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &p) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void printInfo() const override;

  private:
    point_t m_pos;
    double m_width;
    double m_height;
  };
}

#endif
