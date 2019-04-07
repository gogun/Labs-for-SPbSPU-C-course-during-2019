#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
  public:
    Circle(double radius, point_t point);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
    void move(point_t point) override;
    void showCords() const override;
    void showFrameRect() const override;
    void showInfo() const override;

  private:
    double radius_;
    point_t pos_;
};

#endif
