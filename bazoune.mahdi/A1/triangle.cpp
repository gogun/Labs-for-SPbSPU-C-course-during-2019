#include "triangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cassert>

//gravity center 

Triangle::Triangle(const point_t &ptA, const point_t &ptB, const point_t &ptC) :
  pos_({ (ptA.x + ptB.x + ptC.x) / 3 , (ptA.y + ptB.y + ptC.y) / 3 }),
  A_(ptA),
  B_(ptB),
  C_(ptC)
  
{
  assert(getArea() !=0 && "Point of triange must be different!");
}

void Triangle::setPoints(const point_t &ptA, const point_t &ptB, const point_t &ptC)
{
  A_ = ptA;
  B_ = ptB;
  C_ = ptC;
}

double Triangle::getMin(const double &ptA, const double &ptB, const double &ptC)
{
  double min = ptA;
  if (ptB < min)
  {
    min = ptB;
  }
  if (ptC < min)
  {
    min = ptC;
  }
  return min;
}
double Triangle::getMax(const double &ptA, const double &ptB, const double &ptC)
{
  double max = ptA;
  if (ptB > max)
  {
    max = ptB;
  }
  if (ptC > max)
  {
    max = ptC;
  }
  return max;
}
double Triangle::getArea() const
{
  return ((std::abs(((A_.x - C_.x) * (B_.y - C_.y)) - ((A_.y - C_.y) * (B_.x - C_.x))) / 2));
}
rectangle_t Triangle::getFrameRect() const
{
  double max_x = getMax(A_.x, B_.x, C_.x);
  double min_x = getMin(A_.x, B_.x, C_.x);
  double max_y = getMax(A_.y, B_.y, C_.y);
  double min_y = getMin(A_.y, B_.y, C_.y);
  return { max_x - min_x, max_y - min_y, pos_ };
}
point_t Triangle::move(const point_t &point)
{
  A_.x += point.x - pos_.x;
  B_.x += point.x - pos_.x;
  C_.x += point.x - pos_.x;
  A_.y += point.y - pos_.y;
  B_.y += point.y - pos_.y;
  C_.y += point.y - pos_.y;
  pos_ = point;
  return pos_;
}
point_t Triangle::move(double dx, double dy)
{
  pos_.x += dx;
  A_.x += dx;
  B_.x += dx;
  C_.x += dx;
  pos_.y += dy;
  A_.y += dy;
  B_.y += dy;
  C_.y += dy;
  return pos_;
}
void Triangle::print() const
{
  std::cout << '\n';
  std::cout << "Triangle \n ";
  std::cout << '\n';
  std::cout << "XG= " <<  pos_.x << ", " << "YG=" <<  pos_.y << std::endl;
  std::cout << "Ax= " << A_.x << ", " << "Ay= " <<  A_.y << std::endl;
  std::cout << "Bx= " <<  B_.x << ", " << "By= " << B_.y << std::endl;
  std::cout << "Cx= " <<  C_.x << ", " << "Cy= " << C_.y << std::endl;
  std::cout << '\n';
}
