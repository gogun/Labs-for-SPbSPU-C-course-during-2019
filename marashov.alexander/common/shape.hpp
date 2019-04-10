#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace marashov {
  class Shape {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(double dltX, double dltY) = 0;

    virtual void move(const point_t &pos) = 0;

    virtual void scale(double scaleAmount) = 0;

    virtual void writeInfo() const = 0;

  };
}
#endif //SHAPE_HPP
