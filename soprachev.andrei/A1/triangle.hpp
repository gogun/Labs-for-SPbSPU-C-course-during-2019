//
// Created by Andrei Soprachev on 2019-04-01.
//

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &globalVertex0, const point_t &globalVertex1, const point_t &globalVertex2);
  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;

private:
  //in local space
  Vector2 vertex0_;
  Vector2 vertex1_;
  Vector2 vertex2_;
};


#endif //TRIANGLE_HPP
