#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Triangle::Triangle(point_t vertexA, point_t vertexB, point_t vertexC):
    vertex_{vertexA, vertexB, vertexC}
{
  double AB = getSide(vertexA, vertexB);
  double AC = getSide(vertexA, vertexC);
  double BC = getSide(vertexB, vertexC);
  assert(((AB + AC) > BC)
      && "Summary of two triangle's sides must be > third side");
  assert(((AB + BC) > AC)
      && "Summary of two triangle's sides must be > third side");
  assert(((AC + BC) > AB)
      && "Summary of two triangle's sides must be > third side");
  assert(((AB > 0) && (AC > 0) && (BC > 0))
      && "Triangle's vertices can't coincide");
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
  Triangle({x1, y1}, {x2, y2}, {x3, y3})
{ }

point_t Triangle::getCentre() const
{
  return {(vertex_[0].x + vertex_[1].x + vertex_[2].x) / 3, ((vertex_[0].y + vertex_[1].y + vertex_[2].y) / 3)};
}

point_t Triangle::getVertex(int vertexNumber) const
{
  return(vertex_[vertexNumber]);
}

double Triangle::getSide(point_t vertex1, point_t vertex2) const
{
  return (sqrt(pow((vertex1.x - vertex2.x), 2) + pow((vertex1.y - vertex2.y), 2)));
}

double Triangle::getPerimeter() const
{
  return (getSide(vertex_[0], vertex_[1]) + getSide(vertex_[1], vertex_[2])
          + getSide(vertex_[0], vertex_[2]));
}

void Triangle::printParameters() const
{
  for (int i = 0; i <= 2; i++)
  {
    std::cout << "(" << getVertex(i).x << ", " << getVertex(i).y << "); ";
  }
  std::cout << std::endl << std::endl;
}

double Triangle::getArea() const
{
  double semiPerimeter = 0.5 * getPerimeter();
  double side1 = getSide(vertex_[0], vertex_[1]);
  double side2 = getSide(vertex_[1], vertex_[2]);
  double side3 = getSide(vertex_[2], vertex_[0]);
  return (sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3)));
}

double getMax(double number1, double number2, double number3)
{
  if (number1 > number2)
  {
    if (number1 > number3)
    {
      return (number1);
    }
    else
    {
      return (number3);
    }
  }
  else
  {
    if (number2 > number3)
    {
      return (number2);
    }
    else
    {
      return (number3);
    }
  }
}

double getMin(double number1, double number2, double number3)
{
  if (number1 < number2)
  {
    if (number1 < number3)
    {
      return (number1);
    }
    else
    {
      return (number3);
    }
  }
  else
  {
    if (number2 < number3)
    {
      return (number2);
    }
    else
    {
      return (number3);
    }
  }
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX = getMax(vertex_[0].x, vertex_[1].x, vertex_[2].x);
  double maxY = getMax(vertex_[0].y, vertex_[1].y, vertex_[2].y);
  double minX = getMin(vertex_[0].x, vertex_[1].x, vertex_[2].x);
  double minY = getMin(vertex_[0].y, vertex_[1].y, vertex_[2].y);

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
