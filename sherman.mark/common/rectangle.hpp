#ifndef COMMON_RECTANGLE_HPP
#define COMMON_RECTANGLE_HPP
#include "shape.hpp"

namespace sherman
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double, double, const point_t &);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double, double) override;
    void move(const point_t &) override;
    void scale (double) override;
    void printInformation() const override;
  private:
    double width_;
    double height_;
    point_t center_;
  };
}

#endif
