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
  void move(double nX, double nY) override ;
  void printInfo() const override;

private:
  double radius_;
  point_t center_;
};

#endif // CIRCLE_HPP
