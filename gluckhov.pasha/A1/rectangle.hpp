#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, const point_t &newPos);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void displayData() const override;
  void move(double dx, double dy) override;
  void move(const point_t & newPos) override;

private:
  rectangle_t options_;
};
#endif