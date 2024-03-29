#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &, const double, const double);//������ �����

  double getArea() const;
  rectangle_t getFrameRect() const;
  void printInfo() const;
  void move(const point_t &);
  void move(const double &, const double &);

private:
  double height_;
  double width_;
  point_t center_;
};
#endif
