#ifndef RECTANGLE
#define RECTANGLE

#include "shape.hpp"

class Rectangle : Shape
{
  public:
    Rectangle(const rectangle_t&);
    Rectangle(double,double,const point_t&);
    Rectangle(double,double,double,double);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void coutInfo() const override;

    void move(double,double) override;
    void move(const point_t&) override;

  private:
    rectangle_t rect_;
};

#endif // RECTANGLE
