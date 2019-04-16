#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Triangle::Triangle(point_t vertexA, point_t vertexB, point_t vertexC):
    vertex_{vertexA, vertexB, vertexC}
{ }

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
  Triangle({x1, y1}, {x2, y2}, {x3, y3})
{ }

point_t Triangle::getCentre() const
{
  return {(vertex_[0].x + vertex_[1].x + vertex_[2].x) / 3, ((vertex_[0].y + vertex_[1].y + vertex_[2].y) / 3)};
}

double Triangle::getSide(int vertex1, int vertex2) const
{
  return (sqrt(pow((vertex_[vertex1].x - vertex_[vertex2].x), 2) + pow((vertex_[vertex1].y - vertex_[vertex2].y), 2)));
}

double Triangle::getPerimeter() const
{
  return (getSide(0, 1) + getSide(1, 2) + getSide(0, 2));
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
  double semiPerimeter = 0.5 * getPerimeter();
  double side1 = getSide(0, 1);
  double side2 = getSide(1, 2);
  double side3 = getSide(2, 0);

  return (sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3)));
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX = std::max(std::max(vertex_[0].x, vertex_[1].x), vertex_[2].x);
  double maxY = std::max(std::max(vertex_[0].y, vertex_[1].y), vertex_[2].y);
  double minX = std::min(std::min(vertex_[0].x, vertex_[1].x), vertex_[2].x);
  double minY = std::min(std::min(vertex_[0].y, vertex_[1].y), vertex_[2].y);

  return {{(maxX - minX)/2, (maxY - minY)/2}, maxX - minX, maxY - minY};
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

  for (int i = 0; i <= 2; i++)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}
