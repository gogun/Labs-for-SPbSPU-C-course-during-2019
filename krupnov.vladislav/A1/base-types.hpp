#ifndef BASETYPES_HPP
#define BASETYPES_HPP

const float PI = 3.14159265F;

struct point_t
{
	float x;
	float y;
};

struct rectangle_t
{
	float width;
	float height;
	point_t pos;
};
#endif