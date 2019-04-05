#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <string>
#include "shape.hpp"

class Circle : public Shape
{

public:

  Circle(const point_t & center, double radius);
  
  std::string getShapeName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & newCenter) override;
  void move(double dX, double dY) override;

private:
  point_t center_;
  double radius_;
};

#endif // CIRCLE_HPP
