#include "shape.hpp"

class circle :
  public Shape
{
public:
  Circle(float width, float height, float x, float y);
  virtual void getArea() const;
};
