#ifndef RECTANGLE
#define RECTANGLE

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t& position, double width, double height);
  Rectangle(double x, double y, double width, double height);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;
  void show() const override;

private:
  point_t centre_;
  double width_;
  double height_;
};

#endif
