#ifndef A1_CIRCLE
#define A1_CIRCLE

#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t& pos, double radius);
  Circle(double x, double y, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getPos() const override;
  void move(const point_t& centre) override;
  void move(double deltaX, double deltaY) override;

private:
  point_t centre_;
  double radius_;
};

#endif
