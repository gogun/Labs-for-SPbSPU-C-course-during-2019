#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
    double x_, y_;
};

struct rectangle_t
{
    point_t center_;
    double width_, heigth_;
};

#endif
