#ifndef BaseTypes_A2
#define BaseTypes_A2

namespace lukina
{
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
}

#endif
