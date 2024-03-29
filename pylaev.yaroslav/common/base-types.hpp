#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace pylaev {
  struct point_t {
    double x;
    double y;
  };

  struct rectangle_t {
    point_t pos; //coordinates of center
    double width;
    double height;
  };
}

#endif
