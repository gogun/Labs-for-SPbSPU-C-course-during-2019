//
// Created by Артур on 18.03.2019.
//

#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape {
public:
  Circle(const point_t &point, const double &radius);

  point_t getPosition() const;

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &point) override;

  void move(const double &dx, const double &dy) override;

private:
  point_t position_;
  double radius_;
};


#endif //A1_CIRCLE_HPP
