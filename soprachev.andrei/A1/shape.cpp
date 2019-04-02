//
// Created by Andrei Soprachev on 2019-04-01.
//

#include "shape.hpp"

void Shape::move(const point_t &pos)
{
  this->pos = pos;
}

void Shape::move(double dx, double dy)
{
  this->pos += point_t{dx, dy};
}

Shape::Shape(const point_t &pos) :
  pos(pos)
{}

const point_t &Shape::getPos() const
{
  return pos;
}
