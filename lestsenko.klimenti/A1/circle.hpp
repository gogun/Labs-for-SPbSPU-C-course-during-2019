#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double, const point_t &);
  
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &newPos) override;
  void move(double dx, double dy) override;
  point_t getPos() const override;

private:
  double radius_;
  point_t center_;
};

#endif // CIRCLE_HPP
