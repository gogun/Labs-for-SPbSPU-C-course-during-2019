//
// Created by Andrei Soprachev on 2019-04-02.
//

#include "base-types.hpp"
#include <sstream>

std::string point_t::toString() const
{
  std::ostringstream result;
  result << "x = " << std::to_string(this->x) << ", y = " << std::to_string(this->y);
  return result.str();
}

double point_t::magnitude() const
{
  return sqrt(x * x + y * y);
}
