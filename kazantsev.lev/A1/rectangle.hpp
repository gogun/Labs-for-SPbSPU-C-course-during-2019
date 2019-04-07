#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &centre, const double &width, const double &height);
  void setWidth(const double &width);
  void setHeight(const double &height);
  double getWidth() const;
  double getHeight() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &to_position) override;
  void move(const double &dx, const double &dy) override;
  void printShapeInfo() const override;
private:
  double width_;
  double height_;
};
#endif
