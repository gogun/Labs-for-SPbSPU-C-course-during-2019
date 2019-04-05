#ifndef SHAPE_H
#define SHAPE_H
#include "Base-types.hpp"

class Shape
{
  public:
    virtual ~Shape() =default ;

    virtual void move(const double dx,const double dy) =0;
    virtual void move(const point_t &new_p) =0;

    virtual double getArea() const=0;
    virtual rectangle_t getFrameRect() const=0;

    virtual void print() const=0;
};

#endif
