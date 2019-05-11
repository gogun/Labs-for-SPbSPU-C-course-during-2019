#ifndef BASE_TYPES_OF_MG
#define BASE_TYPES_OF_MG

namespace gnatishin
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double height;
    double width;
    point_t pos;
  };
}

#endif
