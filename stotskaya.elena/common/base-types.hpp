#ifndef BASETYPES_HPP_1
#define BASETYPES_HPP_1

namespace stotskaya
{
  struct point_t {
    double x;
    double y;
  };

  struct rectangle_t {
    double width;
    double height;
    point_t pos;
  };
}

#endif // BASETYPES_HPP_1
