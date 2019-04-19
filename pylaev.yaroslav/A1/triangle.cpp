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
  double summX = coordinates_[0].x + coordinates_[1].x + coordinates_[2].x;
  double summY = coordinates_[0].y + coordinates_[1].y + coordinates_[2].y;

  return {summX / 3, summY / 3};
}

double Triangle::getArea() const
{
  point_t side0 = {coordinates_[1].x - coordinates_[0].x, coordinates_[1].y - coordinates_[0].y};
  point_t side2 = {coordinates_[2].x - coordinates_[0].x, coordinates_[2].y - coordinates_[0].y};

  return (0.5 * abs((side0.x * side2.y - side0.y * side2.x)));
}

double Triangle::getSide(const int i) const
{
  assert((i >= 0) && (i < nTops_));

  return sqrt(pow(coordinates_[(i + 1) % nTops_].x - coordinates_[i].x, 2)
      + pow(coordinates_[(i + 1) % nTops_].y - coordinates_[i].y, 2));
}

rectangle_t Triangle::getFrameRect() const
{
  //it's not points of triangle, it's convenient way to save max/min coordinates of triangle
  point_t maxCoordinates = coordinates_[0];
  maxCoordinates.x = std::max(maxCoordinates.x, std::max(coordinates_[1].x, coordinates_[2].x));
  maxCoordinates.y = std::max(maxCoordinates.y, std::max(coordinates_[1].y, coordinates_[2].y));

  point_t minCoordinates = coordinates_[0];
  minCoordinates.x = std::min(minCoordinates.x, std::min(coordinates_[1].x, coordinates_[2].x));
  minCoordinates.y = std::min(minCoordinates.y, std::min(coordinates_[1].y, coordinates_[2].y));

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

void Triangle::move(const point_t & pos)
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
