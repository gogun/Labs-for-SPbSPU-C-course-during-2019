#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, const point_t & position);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t & p) override;
  point_t Center() const override;
  void print() const override;

private:
  double width_;
  double height_;
  point_t pos;
};
#endif /* RECTANGLE_HPP */
