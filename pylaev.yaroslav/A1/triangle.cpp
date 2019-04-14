#include "triangle.hpp"

#include <stdexcept>
#include <cassert>
#include <math.h>
#include <iostream>

Triangle::Triangle(const point_t & center, const double side0, const double side1, const double side2):
  center_(center)
{
  //verification
  if ((side0 <= 0.0) || (side1 <= 0.0) || (side2 <= 0.0)) {
    throw std::invalid_argument("ERROR: Length of triangle's sides must be positive");
  }
  if ((side0 >= side1 + side2) || (side1 >= side0 + side2) || (side2 >= side0 + side1)) {
    throw std::invalid_argument("ERROR: Such triangle is impossible");
  }

  setCoordinates(side0, side1, side2);
}

Triangle::Triangle(const point_t & center, const double side0, const double side1): //isosceles triangle
  center_(center)
{
  const double side2 = side1; //isosceles
  //verification
  if ((side0 <= 0.0) || (side1 <= 0.0)) {
    throw std::invalid_argument("ERROR: Length of triangle's sides must be positive");
  }
  if ((side0 >= side1 + side2) || (side1 >= side0 + side2)) {
    throw std::invalid_argument("ERROR: Such triangle is impossible");
  }

  setCoordinates(side0, side1, side2);
}

Triangle::Triangle(const point_t & center, const double side0): //equilateral triangle
  center_(center)
{
  const double side1 = side0; //equilateral
  const double side2 = side0; //equilateral
  //verification
  if (side0 <= 0.0) {
    throw std::invalid_argument("ERROR: Length of triangle's sides must be positive");
  }
  if (side0 >= side1 + side2) {
    throw std::invalid_argument("ERROR: Such triangle is impossible");
  }

  setCoordinates(side0, side1, side2);
}

void Triangle::setCoordinates(const double & side0, const double & side1, const double & side2)
{
  //set zero-coordinates
  coordinates_[0] = {0, 0};
  coordinates_[2] = {side2, 0};
  coordinates_[1].y = 2 * getArea(side0, side1, side2) / side2;
  int k = 1; //k is coefficient of outside angle
  if ((side1 > side0) && (side1 > side2)) {
    k = -1;
  }
  coordinates_[1].x = k * sqrt(pow(side0, 2) - pow(coordinates_[1].y, 2));
  //set center relatively zero-coordinates
  point_t zeroCenter = {0, 0};
  for (int i = 0; i < nTops_; i++) {
    zeroCenter.x += coordinates_[i].x;
    zeroCenter.y += coordinates_[i].y;
  }
  zeroCenter = {zeroCenter.x / nTops_, zeroCenter.y / nTops_};
  //this delta for translocation triangle from zero-coordinates to normal center
  point_t deltaCoordinates;
  deltaCoordinates.x = center_.x - zeroCenter.x;
  deltaCoordinates.y = center_.y - zeroCenter.y;
  //set normal coordinates
  for (int i = 0; i < nTops_; i++) {
    coordinates_[i].x += deltaCoordinates.x;
    coordinates_[i].y += deltaCoordinates.y;
  }
}

double Triangle::getArea(const double & side0, const double & side1, const double & side2) const //by sides
{
  //s = (p * (p-a) * (p-b) * (p-c))^(1/2)
  double p = 0.0;
  p = (side0 + side1 + side2) / 2; //semi-perimeter
  double s = 1.0;
  s = sqrt((p * (p - side0) * (p - side1) * (p - side2)));

  return s;
}

double Triangle::getArea() const //by coordinates
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
  rectangle_t frameRectangle;
  //it's not points of triangle, it's convenient way to save max/min coordinates of triangle
  point_t maxCoordinates = coordinates_[0];
  point_t minCoordinates = coordinates_[0];
  for (int i = 0; i < nTops_; i++) {
    maxCoordinates.x = fmax(maxCoordinates.x, coordinates_[i].x);
    maxCoordinates.y = fmax(maxCoordinates.y, coordinates_[i].y);
    minCoordinates.x = fmin(minCoordinates.x, coordinates_[i].x);
    minCoordinates.y = fmin(minCoordinates.y, coordinates_[i].y);
  }
  frameRectangle.width = maxCoordinates.x - minCoordinates.x;
  frameRectangle.height = maxCoordinates.y - minCoordinates.y;
  frameRectangle.pos = {frameRectangle.width / 2 + minCoordinates.x, frameRectangle.height / 2 + minCoordinates.y};

  return frameRectangle;
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
  move(center_.x - pos.x, center_.y - pos.y);
}

void Triangle::printSpec() const
{
  std::cout << "Area of our triangle is " << getArea() << " square units\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "Center of the frame rectangle with width = " << frameRectangle.width;
  std::cout << " and height = " << frameRectangle.height;
  std::cout << " is located in point (" << frameRectangle.pos.x << "; " << frameRectangle.pos.y << ")\n";
}
