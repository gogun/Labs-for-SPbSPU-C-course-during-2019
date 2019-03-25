#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(rectangle_t characteristics);
  void move(const point_t &dot) override;
  void move(double deltax, double deltay) override;
  double getArea() const override;
  void writeChanges() const;
  rectangle_t getFrameRect() const override;
private:
  rectangle_t characteristics_;
};

#endif
