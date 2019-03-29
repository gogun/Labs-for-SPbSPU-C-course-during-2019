#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &position, double radius);

  rectangle_t getFrameRect() const;
  double getArea() const;

  void printInfo() const;

private:
  double radius_;
};

#endif //CIRCLE_HPP
