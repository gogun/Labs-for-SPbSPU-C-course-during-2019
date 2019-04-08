#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const double & width, const double & height,const point_t & point);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double & dX, const double & dY) override;
  void move(const point_t & point) override;
  void showInfo() const override;
  void showCords() const override;
  void showFrameRect() const override;

private:
  rectangle_t rect_;
};

#endif
