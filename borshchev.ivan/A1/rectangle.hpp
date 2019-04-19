#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(point_t pos, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double newX, double newY) override;
  void move(const point_t & point) override;
  void dataOutput() const override;

private:
  point_t topLeftPoint_;
  double width_;
  double height_;
};

#endif
