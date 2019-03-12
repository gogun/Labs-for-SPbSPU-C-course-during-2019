#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle() :
  height_(0),
  width_(0),
  frame_rect_({0, 0, {0, 0}}) {}

Rectangle::Rectangle(const point_t& pos, const float height, const float width) :
  height_(height),
  width_(width),
  frame_rect_({height, width, pos})
{
  if (height < 0 || width < 0) {
    throw std::invalid_argument("Area of rectangle is negative.");
  }
}

float Rectangle::getArea() const noexcept
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const noexcept
{
  return frame_rect_;
}

void Rectangle::printData(std::ostream& stream) const
{
  stream << "height : " << height_
      << "\nwidth : " << width_
      << "\nframe rect height : " << frame_rect_.height
      << "\nframe rect width : " << frame_rect_.width
      << "\nposition : (" << frame_rect_.pos.x << ", " << frame_rect_.pos.y << ")\n";
}

void Rectangle::move(const point_t& point) noexcept
{
  frame_rect_.pos = point;
}

void Rectangle::move(const float dx, const float dy) noexcept
{
  frame_rect_.pos.x += dx;
  frame_rect_.pos.y += dy;
}
