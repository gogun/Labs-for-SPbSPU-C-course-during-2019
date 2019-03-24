#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape {
  public:
    virtual float getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual point_t getCenter() const = 0;
    virtual void move(const point_t& pos) = 0;
    virtual void move(float dltX, float dltY) = 0;
};

#endif //SHAPE_HPP
