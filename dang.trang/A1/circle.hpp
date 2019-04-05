#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(point_t point,const double radius);
  virtual double getArea() const;
  rectangle_t getFrameRect() const;
  void prInf() const;
private:
  double radius_;
};