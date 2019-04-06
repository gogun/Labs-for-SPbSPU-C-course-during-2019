#include "shape.hpp"
#include "base-types.hpp"
#include "triangle.hpp"
#include <cmath>
#include <iostream>

Triangle::Triangle(point_t point1, point_t point2, point_t point3):
  top1(point1),
  top2(point2),
  top3(point3),
  pos({(point1.x + point2.x + point3.x)/3,(point1.y + point2.y + point3.y)/3})
{}

double Triangle::getArea() const
{
 return( std::abs(((top2.x - top1.x)*(top3.y - top1.y)-(top3.x - top1.x)*(top2.y- top1.y))/2) );
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX = 0;
  double maxY = 0;
  double minX = 0;
  double minY = 0;
  maxX = std::max(std::max(top1.x, top2.x), top3.x);
  minX = std::min(std::min(top1.x, top2.x), top3.x);
  maxY = std::max(std::max(top1.y, top2.y), top3.y);
  minY = std::min(std::min(top1.y, top2.y), top3.y);
  rectangle_t returnrect;
  returnrect.pos.x = (maxX + minX)/2;
  returnrect.pos.y = (maxY + minY)/2;
  returnrect.width  = maxX - minX;
  returnrect.height = maxY - minY;
  return returnrect;
}

void Triangle::move(const double mX, const double mY)
{
  top1.x += mX;
  top1.y += mY;
  top2.x += mX;
  top2.y += mY;
  top3.x += mX;
  top3.y += mY;
  pos.x += mX;
  pos.y += mY;
}

void Triangle::move(const point_t point)
{
  move(point.x - pos.x,point.y - pos.y);
}

void Triangle::dataoutput() const
{
  std::cout << "area_of_trianglele_=" << getArea() << std::endl;
  std::cout << "framerect_width_height_X_Y_=" << getFrameRect().width << " " << getFrameRect().height << " ";
  std::cout << getFrameRect().pos.x << " " << getFrameRect().pos.y << std::endl;
  std::cout << "position_X_Y_" << pos.x << " " << pos.y << std::endl;
}
