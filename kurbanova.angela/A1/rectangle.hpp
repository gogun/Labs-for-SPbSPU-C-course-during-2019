#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &center, double width1, double height1);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &pos1) override;
  void printInfo() const override;

private:
  point_t pos_;
  double width_, height_;
};

#endif // !RECTANGLE_HPP
