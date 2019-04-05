#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const double &, const double &, const point_t &);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & point) override;
  void move(const double &, const double &) override;
  void printInfo() const override;
private:
  double width_;
  double height_;
  point_t center_;
};

#endif
