#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(point_t vertex1, point_t vertex2, point_t vertex3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & point);
  void move(double dx, double dy) override;
  void showCoord();
  void printCenter();
private:
  point_t vertex_1;
  point_t vertex_2;
  point_t vertex_3;
  point_t center_;
  point_t getCenter() const;
  double getDistance(point_t point1, point_t point2) const;
  double getMinTop(double point1, double point2, double point3) const;
  double getMaxTop(double point1, double point2, double point3) const;
};

#endif //TRIANGLE_HPP
