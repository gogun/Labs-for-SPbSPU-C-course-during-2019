#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

Triangle::Triangle(const point_t& center, double side1, double side2, double side3) :
  center_(center),
  side1_(side1),
  side2_(side2),
  side3_(side3)
{
  assert(((side1 > 0) && (side2 > 0) && (side3 > 0)) && (2 * std::max({side1, side2, side3}) < (side1 + side2 + side3)));
}

double Triangle::getArea() const
{
  double halfPerimeter = (side1_ + side2_ + side3_) / 2;
  return sqrt(halfPerimeter * (halfPerimeter - side1_) * (halfPerimeter - side2_) * (halfPerimeter - side3_));
}

rectangle_t Triangle::getFrameRect() const
{ 
  double frameWidth = side3_;
  //третья вершина треугольника делит "верхнюю ширину" на отрезки длиной x и w-x,считая от левого верхнего угла
  double x = (frameWidth * frameWidth + side1_ * side1_ - side2_ * side2_) / (2 * frameWidth);
  //из теоремы Пифагора
  double frameHeight = sqrt(side1_ * side1_ - x * x);
  //длины медиан, идущих из двух нижних вершин треугольника
  double side1MedianLength = getMedianLength(side1_, side2_, side3_);
  double side2MedianLength = getMedianLength(side2_, side1_, side3_);
  //координата х нижнего левого угла
  double x0 = ((4 * (pow(side1MedianLength, 2) - pow(side2MedianLength, 2)) / (9 * frameWidth)) + 2 * center_.x - frameWidth) / 2;
  //координата y нижнего левого угла
  double y0 = sqrt(pow(2 * side2MedianLength / 3, 2) - pow(x0 - center_.x, 2)) + center_.y;
  point_t frameCenter = {x0 + frameWidth / 2, y0 + frameHeight / 2};
  
  rectangle_t frameRect = {frameWidth, frameHeight, frameCenter};
  return frameRect;
}

void Triangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Triangle::move(const point_t& newPos)
{
  center_ = newPos;
}

void Triangle::printInfo() const
{
  std::cout << "Triangle at " << "(" << center_.x << "," << center_.y << ")" << std::endl;
  std::cout << "Side 1:" << side1_ << std::endl;
  std::cout << "Side 2:" << side2_ << std::endl;
  std::cout << "Side 3:" << side3_ << std::endl;
  std::cout << "Area :" << getArea() << std::endl;
}

double Triangle::getMedianLength(double side1, double side2, double side3) const
{
  return sqrt(2 * side2 * side2 + 2 * side3 * side3 - side1 * side1) / 2;
}
