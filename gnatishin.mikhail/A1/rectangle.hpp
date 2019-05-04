#ifndef RECTANGLE_OF_MG
#define RECTANGLE_OF_MG

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &pos, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getPosition() const override;
  void move(const point_t &center) override;
  void move(double dx, double dy) override;

private:
  point_t center_;
  double width_;
  double height_;
};

#endif
