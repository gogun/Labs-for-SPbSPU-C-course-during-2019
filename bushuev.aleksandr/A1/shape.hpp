#ifndef SHAPE
#define SHAPE

#include "base-types.hpp"

class Shape
{
    public:
        virtual double getArea() const = 0;
        virtual rectangle_t getFrameRect() const = 0;
        virtual void coutInfo() const = 0;

        virtual void move(const point_t&) = 0;
        virtual void move(double,double) = 0;
} ;

#endif // SHAPE
