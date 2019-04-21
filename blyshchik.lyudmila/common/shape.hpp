#ifndef A1_SHAPE_HPP
#define A1_SHAPE_HPP

#include "base-types.hpp"

namespace blyshchik {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t) = 0; //move by center of figure
    virtual void move(double, double) = 0; //move by coordinates x and y
    virtual void print() const = 0;
    virtual void scale(double) = 0;
  };
};
#endif //A1_SHAPE_HPP
