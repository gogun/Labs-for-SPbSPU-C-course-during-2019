#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED
#include "base-types.hpp"

class Shape
{
public:
  Shape(const point_t &);

  virtual double printArea() const = 0;
  virtual rectangle_t printFrameRect() const = 0;
  virtual void printFeatures() const = 0;

  void printData() const;

  virtual void move(const double &, const double &) = 0;
  virtual void move(const point_t &) = 0;

protected:
  point_t m_pos;
};

#endif // SHAPE_HPP_INCLUDED
