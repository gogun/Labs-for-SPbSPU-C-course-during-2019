#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t pos, const double width, const double height);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t point) override;
  void move(const double x, const double y) override;
  void getInfo() const override;
private:
  double width_;
  double height_;
  point_t center_;
};

#endif // !RECTANGLE_HPP
