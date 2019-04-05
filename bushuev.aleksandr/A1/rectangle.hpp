#ifndef RECTANGLE
#define RECTANGLE

#include "shape.hpp"

class Rectangle : Shape
{
  public:
    Rectangle(const point_t &,const double,const double);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printInfo() const override;

    void move(const double,const double) override;
    void move(const point_t&) override;

  private:
    rectangle_t rect_;
};

#endif // RECTANGLE
