//
// Created by Andrei Soprachev on 2019-04-02.
//

#include "base-types.hpp"
#include <sstream>

double point_t::magnitude() const
{
  return sqrt(x * x + y * y);
}
