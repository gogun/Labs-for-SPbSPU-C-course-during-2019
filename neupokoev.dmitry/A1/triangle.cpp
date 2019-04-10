#include "triangle.hpp"
#include <iostream>
#include <cassert>

Triangle::Triangle(const triangle_t &parameters) :
  triangle_(parameters)
{
  assert((triangle_.sideA > 0) && (triangle_.sideB > 0) && (triangle_.sideC > 0));
  assert((triangle_.sideA + triangle_.sideB) > triangle_.sideC);
  assert((triangle_.sideA + triangle_.sideC) > triangle_.sideB);
  assert((triangle_.sideB + triangle_.sideC) > triangle_.sideA);
}

double Triangle::getArea() const
{
  double p = (triangle_.sideA + triangle_.sideB + triangle_.sideC) / 2;
  return sqrt(p * (p - triangle_.sideA) * (p - triangle_.sideB) * (p - triangle_.sideC));
}

rectangle_t Triangle::getFrameRect() const
{
  double area = Triangle::getArea();
  rectangle_t frameRect;
  frameRect.width = triangle_.sideA;
  frameRect.height = area * 2 / triangle_.sideA;
  frameRect.pos = triangle_.pos;
  return frameRect;
}

void Triangle::move(const point_t &pos)
{
  triangle_.pos = pos;
}

void Triangle::move(const double dx, const double dy)
{
  triangle_.pos.x += dx;
  triangle_.pos.y += dy;
}

void Triangle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Triangle side A is " << triangle_.sideA << ","
      << " side B is " << triangle_.sideB << ","
      << " side C is " << triangle_.sideC << " \n"
      << "Triangle centre is (" << triangle_.pos.x << ","
      << triangle_.pos.y << ")\n"
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << "\n"
      << "Area = " << getArea() << "\n\n";
}
