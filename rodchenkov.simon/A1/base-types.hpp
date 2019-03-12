#pragma once
#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t final
{
    float x;
    float y;
};

struct rectangle_t final
{
    float   height;
    float   width;
    point_t pos;
};

#endif
