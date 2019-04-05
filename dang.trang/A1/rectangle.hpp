#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.hpp"


class Rectangle: public Shape
{
  public:
    Rectangle(const point_t &pos,const double width,const double height);

    void move(const double dx,const double dy) override;
    void move(const point_t &new_p) override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void print() const override;

  private:
    rectangle_t rect_;
};

#endif
