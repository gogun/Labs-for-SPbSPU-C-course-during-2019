#ifndef AP_BASE-TYPES

#define AP_BASE-TYPES

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
#endif // AP_BASE-TYPES
