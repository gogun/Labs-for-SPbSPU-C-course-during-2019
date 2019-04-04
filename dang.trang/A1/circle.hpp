#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.hpp"


class Circle: public Shape
{
  public:
    Circle(const point_t &pos,const double radius);

    void move(const double dx,const double dy) override;
    void move(const point_t &new_p) override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void print() const override;
  private:
    point_t center_;
    double radius_;
};

#endif
