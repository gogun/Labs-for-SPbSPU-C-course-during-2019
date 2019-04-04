#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP


#include "base-types.hpp"
#include "Shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &center, double width, double height);

  void move(const point_t &newCenter) override;
  void move(double dx, double dy) override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void writeInfo() const override;

private:
  rectangle_t rectangle_;
};


#endif

