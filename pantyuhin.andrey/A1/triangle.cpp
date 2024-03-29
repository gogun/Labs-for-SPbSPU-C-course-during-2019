#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Triangle::Triangle(point_t vertexA, point_t vertexB, point_t vertexC):
    vertex_{vertexA, vertexB, vertexC}
{
  assert(((vertexC.x - vertexA.x) * (vertexB.y - vertexA.y) != (vertexC.y - vertexA.y) * (vertexB.x - vertexA.x))
      && "vertexes of triangle can't lie on the same straight line or match");
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
  Triangle({x1, y1}, {x2, y2}, {x3, y3})
{ }

point_t Triangle::getCentre() const
{
  return {(vertex_[0].x + vertex_[1].x + vertex_[2].x) / 3, ((vertex_[0].y + vertex_[1].y + vertex_[2].y) / 3)};
}

void Triangle::printParameters() const
{
  for (int i = 0; i <= 2; i++)
  {
    std::cout << "(" << vertex_[i].x << ", " << vertex_[i].y << "); ";
  }
  std::cout << std::endl << std::endl;
}

double Triangle::getArea() const
{
  return fabs((vertex_[0].x - vertex_[2].x) * (vertex_[1].y - vertex_[2].y)
      - (vertex_[1].x - vertex_[2].x) * (vertex_[0].y - vertex_[2].y)) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX = std::max(std::max(vertex_[0].x, vertex_[1].x), vertex_[2].x);
  double maxY = std::max(std::max(vertex_[0].y, vertex_[1].y), vertex_[2].y);
  double minX = std::min(std::min(vertex_[0].x, vertex_[1].x), vertex_[2].x);
  double minY = std::min(std::min(vertex_[0].y, vertex_[1].y), vertex_[2].y);

  return {{minX + (maxX - minX) / 2, minY + (maxY - minY) / 2}, maxX - minX, maxY - minY};
}

void Triangle::move(double dx, double dy)
{
  for (int i = 0; i <= 2; i++)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}

void Triangle::move(point_t newCentre)
{
  point_t oldCentre = getCentre();
  double dx = newCentre.x - oldCentre.x;
  double dy = newCentre.y - oldCentre.y;
  move(dx, dy);
}
