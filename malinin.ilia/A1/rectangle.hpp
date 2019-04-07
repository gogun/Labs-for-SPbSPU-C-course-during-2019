#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
  public:
    Rectangle(double width, double height, point_t point);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dX, double dY) override;
    void move(point_t point) override;
    void showInfo() const override;
    void showCords() const override;
    void showFrameRect() const override;

  private:
    rectangle_t rect_;
};

#endif
