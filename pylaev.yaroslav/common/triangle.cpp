#include "triangle.hpp"

#include <stdexcept>
#include <cassert>
#include <math.h>
#include <iostream>

pylaev::Triangle::Triangle(const point_t & pointA, const point_t & pointB, const point_t & pointC):
  coordinates_({pointA, pointB, pointC})
{
  if (getArea() == 0) {
    throw std::invalid_argument("It's a stright line, coordinates of tops can't be on one line");
  }
}

pylaev::point_t pylaev::Triangle::getCenter() const
{
  return {(coordinates_[0].x + coordinates_[1].x + coordinates_[2].x) / 3,
      (coordinates_[0].y + coordinates_[1].y + coordinates_[2].y) / 3};
}

double pylaev::Triangle::getArea() const //by coordinates
{
  point_t side0 = {coordinates_[1].x - coordinates_[0].x, coordinates_[1].y - coordinates_[0].y}; //like vectors
  point_t side2 = {coordinates_[2].x - coordinates_[0].x, coordinates_[2].y - coordinates_[0].y};

  return (abs((side0.x * side2.y - side0.y * side2.x)) / 2);
}

double pylaev::Triangle::getSide(const int i) const
{
  assert((i >= 0) && (i < nTops_));

  return sqrt(pow(coordinates_[(i + 1) % nTops_].x - coordinates_[i].x, 2)
      + pow(coordinates_[(i + 1) % nTops_].y - coordinates_[i].y, 2));
}

pylaev::rectangle_t pylaev::Triangle::getFrameRect() const
{
  //max/min coordinates of triangle (left top and rigth bottom)
  point_t maxCoordinates {std::max(coordinates_[0].x, std::max(coordinates_[1].x, coordinates_[2].x)),
      std::max(coordinates_[0].y, std::max(coordinates_[1].y, coordinates_[2].y))};
  point_t minCoordinates {std::min(coordinates_[0].x, std::min(coordinates_[1].x, coordinates_[2].x)),
      std::min(coordinates_[0].y, std::min(coordinates_[1].y, coordinates_[2].y))};

  double width = maxCoordinates.x - minCoordinates.x;
  double height = maxCoordinates.y - minCoordinates.y;
  point_t pos = {width / 2 + minCoordinates.x, height / 2 + minCoordinates.y};

  return {pos, width, height};
}

void pylaev::Triangle::move(const double dx, const double dy)
{
  for (int i = 0; i < nTops_; i++) {
    coordinates_[i].x += dx;
    coordinates_[i].y += dy;
  }
}

void pylaev::Triangle::move(const point_t & pos)
{
  point_t center = getCenter();
  move(pos.x - center.x, pos.y - center.y);
}

void pylaev::Triangle::scale(const double kScaling)
{
  if (kScaling <= 0.0) {
    throw std::invalid_argument("Coefficient of scaling must be positive");
  }

  point_t pos = getCenter();
  for (int i = 0; i < nTops_; i++) {
    coordinates_[i] = {coordinates_[i].x * kScaling + pos.x * (1 - kScaling), 
        coordinates_[i].y * kScaling + pos.y * (1 - kScaling)};
  }
}

void pylaev::Triangle::printSpec() const
{
  std::cout << "Area of our triangle is " << getArea() << " square units\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "Center of the frame rectangle with width = " << frameRectangle.width
      << " and height = " << frameRectangle.height
      << " is located in point (" << frameRectangle.pos.x << "; " << frameRectangle.pos.y << ")\n";
}
