//
// Created by Andrei Soprachev on 2019-04-01.
//

#ifndef LAB1_TRIANGLE_HPP
#define LAB1_TRIANGLE_HPP


#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &posCenterOfMass, const point_t &localVertice0, const point_t &localVertice1,
    const point_t &localVertice2);

  Triangle(const point_t &globalVertice0, const point_t &globalVertice1, const point_t &globalVertice2);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

private:
  //in local space
  point_t vertice0;
  point_t vertice1;
  point_t vertice2;
};


#endif //LAB1_TRIANGLE_HPP
