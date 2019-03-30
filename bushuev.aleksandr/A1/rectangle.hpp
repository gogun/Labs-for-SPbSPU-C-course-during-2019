#ifndef RECTANGLE
#define RECTANGLE

#include "shape.hpp"

class Rectangle : Shape
{
  public:
    Rectangle(const point_t &center,double width,double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void coutInfo() const override;

    void move(double,double) override;
    void move(const point_t&) override;

  private:
    rectangle_t rect_;
};

#endif // RECTANGLE
