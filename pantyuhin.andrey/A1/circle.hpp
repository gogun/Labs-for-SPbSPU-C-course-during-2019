#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:  

  Circle(point_t centre, double radius);
  Circle(double x, double y, double radius);
  
  point_t getPos() const;
  double getRadius() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t centre) override;

private:

  point_t centre_;
  double radius_;
};

#endif //CIRCLE_HPP
