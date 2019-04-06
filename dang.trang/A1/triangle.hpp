#ifndef triangle_hpp
#define triangle_hpp
#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{
public:
  Triangle(point_t point1, point_t point2, point_t point3);

  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const double mX, const double mY);
  void move(const point_t point);
  void dataoutput() const;

private:
  point_t top1;
  point_t top2;
  point_t top3;
  point_t pos;
};

#endif
