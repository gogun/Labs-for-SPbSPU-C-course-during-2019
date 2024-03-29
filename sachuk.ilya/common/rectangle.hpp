#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace sachuk
{
  class Rectangle : public Shape {
  public:
    Rectangle(const point_t & point, double w, double h);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & point) override;
    void move(double dx, double dy) override;
    void printInfo() const override;
    void scale(double multiplier) override;

  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif //RECTANGLE_HPP
