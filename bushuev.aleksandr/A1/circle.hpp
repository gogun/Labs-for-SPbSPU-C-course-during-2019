#ifndef CIRCLE
#define CIRCLE

#include "shape.hpp"

class Circle : Shape
{
  public:
    Circle(const point_t &,const double);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void printInfo() const override;

    void move(const double,const double) override;
    void move(const point_t &) override;

  private:
    point_t center_;
    double radius_;
};
#endif // CIRCLE
