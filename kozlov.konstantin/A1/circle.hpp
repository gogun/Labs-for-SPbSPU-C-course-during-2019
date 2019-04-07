#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const double radius, const point_t & center);
  virtual void printData() const override;
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t & cpos) override;
  virtual void move(const double cx, const double cy) override;

private:
  point_t center_;
  double radius_;
};

#endif
