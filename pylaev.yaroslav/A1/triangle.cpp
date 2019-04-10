#include "triangle.hpp"

#include <stdexcept>
#include <cassert>
#include <math.h>
#include <iostream>

Triangle::Triangle(const point_t &center, const double *sides):
  center_(center)
{
//inicialization
  for (int i = 0; i < nTops_; i++) {
    sides_[i] = *(sides + i);
  }
//verification
  for (int i = 0; i < nTops_; i++) {
    if (sides_[i] >= sides_[(i+1) % nTops_] + sides_[(i+2) % nTops_]) {
      throw std::invalid_argument("ERROR: Such triangle is impossible");
    }
    if (sides_[i] <= 0.0) {
      throw std::invalid_argument("ERROR: Lenght of triangle's sides must be positive");
    }
  }
  setCoordinates();
}

Triangle::Triangle(const point_t &center, const double side):
  center_(center)
{
//inicialization
  for (int i = 0; i < nTops_; i++) {
    sides_[i] = side;
    //verification
    if (sides_[i] <= 0) {
      throw std::invalid_argument("ERROR: Lenght of triangle's sides must be positive");
    }
  }
  setCoordinates();
}

void Triangle::setCoordinates()
{
  //set zero-coordinates
  coordinates_[0] = {0, 0};
  coordinates_[2] = {sides_[2], 0};
  coordinates_[1].y = 2 * getArea() / sides_[2];
  int k = 1;   //k is coefficient of outside angle
  if ((sides_[1] > sides_[0]) && (sides_[1] > sides_[2])){
    k = -1;
  }
  coordinates_[1].x = k * sqrt(pow(sides_[0], 2) - pow(coordinates_[1].y, 2));
  //set center relatively zero-coordinates
  point_t zeroCenter = {0, 0};
  for (int i = 0; i < nTops_; i++) {
    zeroCenter.x += coordinates_[i].x;
    zeroCenter.y += coordinates_[i].y;
  }
  zeroCenter = {zeroCenter.x / nTops_, zeroCenter.y / nTops_};
  //this delta for translocation triangle from
  //zero-coordinates to normal center
  point_t deltaCoordinates;
  deltaCoordinates.x = center_.x - zeroCenter.x;
  deltaCoordinates.y = center_.y - zeroCenter.y;
  //set normal coordinates
  for (int i = 0; i < nTops_; i++) {
    coordinates_[i].x += deltaCoordinates.x;
    coordinates_[i].y += deltaCoordinates.y;
  }
}

double Triangle::getArea() const
{
  //s = (p * (p-a) * (p-b) * (p-c))^(1/2)
  double p = 0.0;
  for (int i = 0; i < nTops_; i++) {
    p += sides_[i]; //perimeter
  }
  p /= 2; //semi-perimeter
  double s = 1.0;
  for (int i = 0; i < nTops_; i++) {
    s *= (p - sides_[i]);
  }
  s = sqrt((p * s));

  return s;
}

double Triangle::getSide(const int i) const
{
  assert((i >= 0) && (i < nTops_));
  return sides_[i];
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

void Triangle::move(const point_t &pos) {
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
