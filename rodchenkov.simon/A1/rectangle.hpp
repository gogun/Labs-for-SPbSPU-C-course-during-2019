#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle final : public Shape
{
public:
  Rectangle();
  Rectangle(const point_t& pos, const double height, const double width);

  double      getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void        printData(std::ostream& stream) const override;
  void        move(const point_t& point) noexcept override;
  void        move(const double   dx, const double dy) noexcept override;

private:
  double      height_;
  double      width_;
  rectangle_t frame_rect_;
};

#endif // RECTANGLE_HPP
