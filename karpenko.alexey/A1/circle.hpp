#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const double radius, const point_t &center);
<<<<<<< HEAD
  
=======
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t &newPos) override;

private:
  double radius_;
  point_t center_;
};
#endif
