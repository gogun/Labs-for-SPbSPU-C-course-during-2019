//
// Created by Andrei Soprachev on 2019-03-19.
//

#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  point_t pos;
  double width;
  double height;
};

#endif //BASE_TYPES_HPP
