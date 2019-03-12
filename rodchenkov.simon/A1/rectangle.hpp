#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle final : public Shape
{
public:
  Rectangle();
  Rectangle(const point_t pos, const float height, const float width);

  float       getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void        printData(std::ostream& stream) const override;

  void move(const point_t point) noexcept override;
  void move(const float   dx, const float dy) noexcept override;

private:
  float       height_;
  float       width_;
  rectangle_t frame_rect_;
};

#endif
