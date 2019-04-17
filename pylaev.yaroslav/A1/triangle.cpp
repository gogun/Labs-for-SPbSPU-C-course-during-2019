#include "triangle.hpp"

#include <stdexcept>
#include <cassert>
#include <math.h>
#include <iostream>

Triangle::Triangle(const point_t & pointA, const point_t & pointB, const point_t & pointC):
  coordinates_({pointA, pointB, pointC})
{
  if (getArea() == 0.0) {
    throw std::invalid_argument("It's a stright line, coordinates of tops can't be on one line");
  }
  center_ = getCenter();
}

point_t Triangle::getCenter() const
{
  point_t center = {0.0, 0.0};
  for (int i = 0; i < nTops_; i++) {
    center.x += coordinates_[i].x;
    center.y += coordinates_[i].y;
  }
  return {center.x / 3, center.y / 3};
}

double Triangle::getArea() const
{
  const int i = 0;

  point_t side0 = {0.0, 0.0};
  side0.x = coordinates_[i + 1].x - coordinates_[i].x;
  side0.y = coordinates_[i + 1].y - coordinates_[i].y;

  point_t side2 = {0.0, 0.0};
  side2.x = coordinates_[i + 2].x - coordinates_[i].x;
  side2.y = coordinates_[i + 2].y - coordinates_[i].y;

  return (0.5 * abs((side0.x * side2.y - side0.y * side2.x)));
}

double Triangle::getSide(const int i) const
{
  assert((i >= 0) && (i < nTops_));

  return sqrt(pow(coordinates_[i + 1].x - coordinates_[i].x, 2) + pow(coordinates_[i + 1].y - coordinates_[i].y, 2));
}

rectangle_t Triangle::getFrameRect() const
{
  //it's not points of triangle, it's convenient way to save max/min coordinates of triangle
  point_t maxCoordinates = coordinates_[0];
  point_t minCoordinates = coordinates_[0];
  for (int i = 1; i < nTops_; i++) {
    maxCoordinates.x = std::max(maxCoordinates.x, coordinates_[i].x);
    maxCoordinates.y = std::max(maxCoordinates.y, coordinates_[i].y);
    minCoordinates.x = std::min(minCoordinates.x, coordinates_[i].x);
    minCoordinates.y = std::min(minCoordinates.y, coordinates_[i].y);
  }

  double width = maxCoordinates.x - minCoordinates.x;
  double height = maxCoordinates.y - minCoordinates.y;
  point_t pos = {width / 2 + minCoordinates.x, height / 2 + minCoordinates.y};

  return {pos, width, height};
}

void Triangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
  for (int i = 0; i < nTops_; i++) {
    coordinates_[i].x += dx;
    coordinates_[i].y += dy;
  }
}

void Triangle::move(const point_t &pos)
{
  move(pos.x - center_.x, pos.y - center_.y);
}

void Triangle::printSpec() const
{
  std::cout << "Area of our triangle is " << getArea() << " square units\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "Center of the frame rectangle with width = " << frameRectangle.width;
  std::cout << " and height = " << frameRectangle.height;
  std::cout << " is located in point (" << frameRectangle.pos.x << "; " << frameRectangle.pos.y << ")\n";
}
