#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &, double, double);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double, double);
  void move(const point_t &);

private:
  point_t center_;
  double width_;
  double height_;
  double area_;
  rectangle_t frameRect_;
};

#endif // RECTANGLE_HPP
