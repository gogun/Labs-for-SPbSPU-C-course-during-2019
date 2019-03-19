#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <ostream>

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;

  virtual double       getArea() const noexcept = 0;
  virtual rectangle_t getFrameRect() const noexcept = 0;
  virtual void        printData(std::ostream& stream) const = 0;

  virtual void move(const point_t& point) noexcept = 0;
  virtual void move(const double   dx, const double dy) noexcept = 0;
};

#endif
