#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  // In triangle we set 3 dots: center_, pointA_ and pointB_
  Triangle(const point_t &, const point_t &, const point_t &);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t &newPoint);
  void move(double dx, double dy);
  void inform() const;
  
private:
  point_t center_;
  point_t pointA_, pointB_, pointC_;
  double a_, b_, c_;
};

#endif
