#include "rectangle.hpp"
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

Rectangle::Rectangle(double Wid, double Hei, double xrect, double yrect):
  rrect_{Wid, Hei, {xrect, yrect}}
{
}

double Rectangle::getArea() const
{
  return rrect_.height * rrect_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {rrect_.height, rrect_.width, rrect_.pos.x, rrect_.pos.y};
}

void Rectangle::move(double mX, double mY)
{
  rrect_.pos.x += mX;
  rrect_.pos.y += mY;
}

void Rectangle::move(const point_t &point)
{
  rrect_.pos.x = point.x;
  rrect_.pos.y = point.y;
}

void Rectangle::dataoutput() const
{
  std::cout << "area_of_rectangle_=" << getArea() << std::endl
			<< "framerect_width_height_X_Y_=" << getFrameRect().width << " " << getFrameRect().height << " "
		    << getFrameRect().pos.x << " " << getFrameRect().pos.y << std::endl
		    << "position_X_Y_" << rrect_.pos.x << " " << rrect_.pos.y << std::endl;
}
