#ifndef CIRCLE
#define CIRCLE

#include "shape.hpp"

class Circle : Shape
{
  public:
    Circle(const point_t &center,double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void coutInfo() const override;

    void move(double,double) override;
    void move(const point_t&) override;

  private:
    point_t center_;
    double radius_;
};
#endif // CIRCLE
