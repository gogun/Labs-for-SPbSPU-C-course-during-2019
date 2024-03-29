#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace utin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t &, const double &, const double &);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double &, const double &) override;
    void move(const point_t &) override;
    void scale(double) override;
    void printInfo() const override;
  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif
