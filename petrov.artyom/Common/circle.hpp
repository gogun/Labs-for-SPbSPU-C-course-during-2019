#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include "shape.hpp"

namespace petrov
{

  class Circle : public Shape
  {
  public:
    explicit Circle(point_t centre, double radius);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t & centre) override;

    void move(double dx, double dy) override;

    point_t getCentre() const;

    double getRadius() const;

  private:
    point_t centre_;
    double radius_;
  };

}

#endif //CIRCLE_HPP
