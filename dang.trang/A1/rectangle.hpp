#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(point_t point,const double width,const double height);
  virtual double getArea() const;
  rectangle_t getFrameRect() const;
  void prInf() const;
private:
  double width_, height_;
};