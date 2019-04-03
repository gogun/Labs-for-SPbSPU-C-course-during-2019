#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t & center, double radius);
  Circle(double centerX, double centerY, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & pos) override ;
  void move(double dX, double Y) override ;
  void printInfo() const override;

private:
  point_t center_;
  double radius_;
  };

#endif // CIRCLE_HPP
