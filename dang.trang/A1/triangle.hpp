#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(point_t point1, point_t point2, point_t point3);
  virtual double getArea() const;
  void center(point_t point1, point_t point2, point_t point3);
  rectangle_t getFrameRect() const;
  void prInf() const;
private:
  point_t c1, c2, c3;
};