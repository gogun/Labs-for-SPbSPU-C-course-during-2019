#include "shape.hpp"

class Rectangle :
  public Shape
{
public:
  Rectangle(float width, float height, float x, float y);
  virtual void getArea() const;
};
