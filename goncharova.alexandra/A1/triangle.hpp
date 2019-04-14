#ifndef triangle_hpp
#define triangle_hpp
#include "shape.hpp"

class Triangle : public Shape
{
public:
  point_t center_;
  point_t pointA_, pointB_, pointC_;
  double a_, b_, c_;
  Triangle(const point_t &, const point_t &, const point_t &, const point_t &);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t &newPoint);
  void move(double dx, double dy);
  void inform() const;
};

#endif
