//
// Created by Andrei Soprachev on 2019-04-02.
//

#include "base-types.hpp"

std::string point_t::toString() const
{
  return " x = " + std::to_string(this->x) + ", y = " + std::to_string(this->y);
}

double point_t::magnitude() const
{
  return sqrt(x*x + y*y);
}
