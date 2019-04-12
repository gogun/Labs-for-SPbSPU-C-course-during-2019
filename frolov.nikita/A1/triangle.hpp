#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle: public  Shape
{
public:
   Triangle(point_t point0, point_t point1, point_t point3);
   void move(double dx, double dy) override;
   void move(const point_t &center) override;
   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void showPoint() const override;
private:
  point_t point0_;
  point_t point1_;
  point_t point2_;
  point_t center_;
};

#endif
