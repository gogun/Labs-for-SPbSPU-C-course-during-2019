#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  // In triangle we set 3 dots: pointA_, pointB_ and pointC_
  Triangle(const point_t &, const point_t &, const point_t &);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void shift(const point_t &, const point_t &, const point_t &);
  void move(const point_t &newPoint);
  void move(double dx, double dy);
  void inform() const;
  
private:
  point_t pointA_, pointB_, pointC_;
  point_t center_;
};

#endif
