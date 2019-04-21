#include "circle.hpp"
#include <math.h>
#include <stdexcept>

kraynov::Circle::Circle(const point_t &pos, double radius) :
	center_(pos),
	radius_(radius)
{
	if (radius < 0)
	{
		throw std::invalid_argument("Attempted creation of a circle with a radius less than 0");
	}
}

kraynov::point_t kraynov::Circle::getPos() const
{
	return center_;
}

double kraynov::Circle::getArea() const
{
	return M_PI * pow(radius_, 2);
}

void kraynov::Circle::move(const point_t &dest)
{
	center_ = dest;
}

void kraynov::Circle::move(double shift_x, double shift_y)
{
	center_.x += shift_x;
	center_.y += shift_y;
}

kraynov::rectangle_t kraynov::Circle::getFrameRect() const
{
	return {center_, 2 * radius_, 2 * radius_};
}

void kraynov::Circle::scale(double multiplicator)
{
	if (multiplicator <= 0)
	{
		throw std::invalid_argument("Attempted scaling by number lower than 0");
	}

	radius_ *= multiplicator;
}
