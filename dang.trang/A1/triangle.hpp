#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.hpp"


class Triangle: public Shape
{
  public:
    Triangle(const point_t &pA,const point_t &pB,const point_t &pC);

    void move(const double dx,const double dy) override;
    void move(const point_t &new_p) override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void print() const override;

  private:
    point_t point_a_,point_b_,point_c_;
    point_t center_;
    double getDistance(const point_t &point_1,const point_t &point_2) const;
};

#endif
