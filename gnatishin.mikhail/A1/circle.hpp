#ifndef CIRCLE_OF_MG
#define CIRCLE_OF_MG

#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &pos, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getPosition() const override;
  void move(const point_t &center) override;
  void move(double dx, double dy) override;

private:
  point_t center_;
  double radius_;
};

#endif
