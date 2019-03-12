#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "base-types.hpp"
#include <ostream>

class Shape
{
public:
  virtual float       getArea() const noexcept = 0;
  virtual rectangle_t getFrameRect() const noexcept = 0;
  virtual void        printData(std::ostream& stream) const = 0;

  virtual void move(const point_t point) noexcept = 0;
  virtual void move(const float   dx, const float dy) noexcept = 0;

  virtual ~Shape() = default;
};

#endif
