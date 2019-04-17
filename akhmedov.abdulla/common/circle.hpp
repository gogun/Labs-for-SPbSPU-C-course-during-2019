#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP
#include "shape.hpp"

namespace akhmedov
{
  class Circle : public Shape
  {
    public:
      Circle(const point_t &pos, double radius);

      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t &pos) override;
      void move(double dx, double dy) override;
      void printInfo() const override;
      point_t getCenter() const override;
      void scale(double multiplyCoefficient) override;
      double getRadius() const;

    private:
      point_t pos_;
      double radius_;
  };
}

#endif
