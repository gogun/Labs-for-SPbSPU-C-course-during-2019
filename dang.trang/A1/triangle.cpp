#include "triangle.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>

Triangle::Triangle(point_t point1, point_t point2, point_t point3) :Shape({ (point1.x+point2.x+point3.x) / 3,(point1.y+point2.y+point3.y) / 3 }), c1(point1), c2(point2), c3(point3)
{
}

void Triangle::center(point_t point1, point_t point2, point_t point3)
{
  center_.x = (point1.x + point2.x + point3.x) / 3;
  center_.y = (point1.y + point2.y + point3.y) / 3;
}


rectangle_t Triangle::getFrameRect() const
{
  rectangle_t frame = { 1,1,{0,0} };
  double xPos[] = { c1.x,c2.x,c3.x };
  double yPos[] = { c1.y,c2.y,c3.y };
  double maxX = *std::max_element(xPos, xPos + 3);
  double minX = *std::min_element(xPos, xPos + 3);
  double maxY = *std::max_element(yPos, yPos + 3);
  double minY = *std::min_element(yPos, yPos + 3);
  frame.pos.x = (maxX + minX) / 2;
  frame.pos.y = (maxY + minY) / 2;
  frame.height = maxY - minY;
  frame.width = maxX - minX;
  return frame;
}

double Triangle::getArea() const
{
  double  area=0;
  area = fabs(0.5*((c1.x - c3.x)*(c2.y - c3.y) - (c2.x - c3.x)*(c1.y - c3.y)));
  return area;
}

void Triangle::prInf() const
{
  std::cout << "Centre on Ox "<< center_.x<<" centre on Oy "<< center_.y<<std::endl;
  std::cout << "Vertex 1 " << c1.x <<" "<< c1.y << " Vertex 2 " << c2.x << " " << c2.y << " Vertex 3 " << c3.x << " " << c3.y<<std::endl;
}