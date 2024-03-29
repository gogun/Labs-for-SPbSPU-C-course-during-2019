#ifndef BASE_TYPES_H
#define BASE_TYPES_H

namespace kornilov
{
  struct point_t
  {
    double x, y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width, height;
  };
}

#endif
