#ifndef circle_hpp
#define circle_hpp
#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(double Rcircle, point_t cpoint);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const double mX, const double mY);
  void move(const point_t point);
  void dataoutput() const;

private:
  double cR;
  point_t pos;
};
#endif
