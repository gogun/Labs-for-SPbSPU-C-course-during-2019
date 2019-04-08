#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, const point_t & center);
  double getArea() const;
  rectangle_t getFrameRect() const override;
  void move(const point_t & new_point) override;
  void move(double x_delta, double y_delta) override;
  void getInfo() const override;

private:
  double width_;
  double height_;
  point_t center_;
};


#endif
