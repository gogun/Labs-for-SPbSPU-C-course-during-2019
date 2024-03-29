#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t &, double width, double height);

  double getArea() const override;
  void printInfo() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &) override;
  void move(double dx, double dy) override;

private:
  point_t center_;
  double width_;
  double height_;
};

#endif //RECTANGLE_HPP
