#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include "shape.hpp"

class Rectangle : public Shape
{
public:
  explicit Rectangle(rectangle_t rectangle);
  explicit Rectangle(point_t centre, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & centre) override;
  void move(double dx, double dy) override;

  point_t getCentre() const;
  double getWidth() const;
  double getHeight() const;
private:
  rectangle_t rectangle_;
};


#endif //RECTANGLE_HPP
