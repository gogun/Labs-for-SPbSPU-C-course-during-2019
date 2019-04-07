#include "shape.hpp"

Shape::Shape(const point_t &centre) :
  pos_(centre)
{
}
point_t Shape::getCentre() const
{
  return pos_;
}
