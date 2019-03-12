#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle final : public Shape
{
public:
  Circle();
  Circle(const point_t pos, const float radius);

  float       getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void        printData(std::ostream& stream) const override;

  void move(const point_t point) noexcept override;
  void move(const float   dx, const float dy) noexcept override;

private:
  float       radius_;
  rectangle_t frame_rect_;
};

#endif
