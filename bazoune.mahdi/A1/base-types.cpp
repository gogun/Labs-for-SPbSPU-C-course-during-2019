#include "base-types.hpp"

std::ostream & operator <<(std::ostream& os, const point_t& r)
{
  return os << '('
    << r.x << ", " << r.y
    << ')';
}

std::ostream & operator <<(std::ostream& os, const rectangle_t& r)
{
  return os << r.pos
    << " width " << r.width
    << " height " << r.height;
}

