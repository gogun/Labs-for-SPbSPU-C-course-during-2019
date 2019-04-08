#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t &center, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &goal) override;
  void move(double dx, double dy) override;
  void show() const override;

private:
  point_t center_;
  double radius_;
};

#endif /* Circle_hpp */
