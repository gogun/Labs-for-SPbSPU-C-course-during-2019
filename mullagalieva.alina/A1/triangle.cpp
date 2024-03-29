#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t& posA, const point_t& posB, const point_t& posC) :
  centre_({(posA.x + posB.x + posC.x) / 3, (posA.y + posB.y + posC.y) / 3}),
  posA_(posA),
  posB_(posB),
  posC_(posC)
{
  assert(std::abs((posB.x - posA.x) * (posC.y - posA.y)
      - (posB.y - posA.y) * (posC.x - posA.x)) > 0.000001); //points shouldn't lie on the same line
}

double Triangle::getArea() const
{
  double s = std::abs((posC_.x - posA_.x) * (posC_.y - posB_.y)
      - (posC_.y - posA_.y) * (posC_.x - posB_.x)) / 2;
  return s;
}

rectangle_t Triangle::getFrameRect() const
{
  double max_x = fmax(fmax(posA_.x, posB_.x), posC_.x);
  double min_x = fmin(fmin(posA_.x, posB_.x), posC_.x);
  double max_y = fmax(fmax(posA_.y, posB_.y), posC_.y);
  double min_y = fmin(fmin(posA_.y, posB_.y), posC_.y);
  return {max_x - min_x, max_y - min_y, {(max_x + min_x) / 2, (max_y + min_y) / 2}};
}

void Triangle::move(const point_t& point)
{
  double dx = point.x - centre_.x;
  double dy = point.y - centre_.y;
  move(dx, dy);
}

void Triangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
  posA_.x += dx;
  posB_.x += dx;
  posC_.x += dx;
  posA_.y += dy;
  posB_.y += dy;
  posC_.y += dy;
}

void Triangle::show() const
{
  std::cout << "Triangle" << "\n";
  std::cout << "Position of the figure: ("
      << centre_.x << "; " << centre_.y << ")" << "\n";
  std::cout << "Coordinates:" << "\n";
  std::cout << "A: (" << posA_.x << "; " << posA_.y << ")" << "\n";
  std::cout << "B: (" << posB_.x << "; " << posB_.y << ")" << "\n";
  std::cout << "C: (" << posC_.x << "; " << posC_.y << ")" << "\n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "Frame Rectangle centre: ("
      << getFrameRect().pos.x << "; " << getFrameRect().pos.y << ")" << "\n";
  std::cout << "Frame Rectangle width: " << getFrameRect().width << "\n";
  std::cout << "Frame Rectangle height: " << getFrameRect().height << "\n";
}
