#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t { //_t - if structure contains only data fields
  double x;
  double y;
};
struct rectangle_t {
  double width;
  double height;
  point_t pos; //coordinates of center
};

#endif
