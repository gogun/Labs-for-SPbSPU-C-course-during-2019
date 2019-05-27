#ifndef SEPARATION_HPP
#define SEPARATION_HPP

#include "composite-shape.hpp"
#include "matrix.hpp"

namespace gusarov
{
  Matrix<Shape> section(const CompositeShape &);
  bool intersect(const rectangle_t &, const rectangle_t &);
}

#endif
