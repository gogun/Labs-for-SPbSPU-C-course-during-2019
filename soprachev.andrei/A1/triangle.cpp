//
// Created by Andrei Soprachev on 2019-04-01.
//

#include "triangle.hpp"
#include "math.h"

point_t centerOfMassByVertice(const point_t &vertice0, const point_t &vertice1, const point_t &vertice2)
{
  return (vertice0 + vertice1 + vertice2) / 3;
}


//задание треугольника центром масс и тремя точками относительно него
Triangle::Triangle(const point_t &posCenterOfMass, const point_t &localVertice0, const point_t &localVertice1,
  const point_t &localVertice2) :
  Shape(posCenterOfMass),
  vertice0(localVertice0),
  vertice1(localVertice1),
  vertice2(localVertice2)
{
  //вершины должны задавть треугольник центр масс которого совпадает с началом координат
  point_t trueCenterOfMass = centerOfMassByVertice(vertice0, vertice1, vertice2);
  assert(trueCenterOfMass.x == 0 && trueCenterOfMass.y == 0);

  //длина каждой стороны меньше суммы двух других
  double lenght01 = (vertice0 - vertice1).magnitude();
  double lenght12 = (vertice1 - vertice2).magnitude();
  double lenght20 = (vertice2 - vertice0).magnitude();
  assert(lenght01 < lenght12 + lenght20);
  assert(lenght12 < lenght01 + lenght20);
  assert(lenght20 < lenght12 + lenght01);

}

//задание треугольника тремя координатами
Triangle::Triangle(const point_t &globalVertice0, const point_t &globalVertice1, const point_t &globalVertice2) :
  Shape(centerOfMassByVertice(globalVertice0, globalVertice1, globalVertice2))
{

  //перевод глобальных координат в локальные (относительно центра масс)
  vertice0 = globalVertice0 - pos;
  vertice1 = globalVertice1 - pos;
  vertice2 = globalVertice2 - pos;
  double lenght01 = (vertice0 - vertice1).magnitude();
  double lenght12 = (vertice1 - vertice2).magnitude();
  double lenght20 = (vertice2 - vertice0).magnitude();
  assert(lenght01 < lenght12 + lenght20);
  assert(lenght12 < lenght01 + lenght20);
  assert(lenght20 < lenght12 + lenght01);
}

//объём через определитель матрицы
double Triangle::getArea() const
{
  double a = (vertice0.x - vertice2.x) * (vertice1.y - vertice2.y);
  double b = (vertice1.x - vertice2.x) * (vertice0.y - vertice2.y);
  double det = a - b;
  return abs(.5 * det);
}

//минимальное значение из трёх
double minOfVal(double d0, double d1, double d2)
{
  return (d0 < d1) ?
         ((d0 < d2) ? d0 : d2) :
         ((d1 < d2) ? d1 : d2);
}

//максимальное значение из трёх
double maxOfVal(double d0, double d1, double d2)
{
  return (d0 > d1) ?
         ((d0 > d2) ? d0 : d2) :
         ((d1 > d2) ? d1 : d2);
}

rectangle_t Triangle::getFrameRect() const
{
  double left = minOfVal(vertice0.x, vertice1.x, vertice2.x);
  double right = maxOfVal(vertice0.x, vertice1.x, vertice2.x);
  double down = minOfVal(vertice0.y, vertice1.y, vertice2.y);
  double up = maxOfVal(vertice0.y, vertice1.y, vertice2.y);

  rectangle_t result;
  result.width = right - left;
  result.height = up - down;

  result.pos = point_t
    {
      this->pos.x + left + (result.width / 2),
      this->pos.y + down + (result.height / 2)
    };

  return result;
}
