#include "base-types.hpp"

class Shape
{
  public:
    Shape(point_t pos);
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void displayData() const = 0;
  private:
    point_t pos_;
};
