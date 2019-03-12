#include "circle.hpp"
#include <stdexcept>

const float PI = atan(1) * 4;

Circle::Circle() :
  radius_(0),
  frame_rect_({0, 0, {0, 0}}) {}

Circle::Circle(const point_t pos, const float radius) :
  radius_(radius),
  frame_rect_({radius * 2, radius * 2, pos})
{
  if (radius < 0) {
    throw std::invalid_argument("Area of circle is negative.");
  }
}

float Circle::getArea() const noexcept
{
    return pow(radius_, 2) * PI;
}

rectangle_t Circle::getFrameRect() const noexcept
{
    return  frame_rect_;
}

void Circle::printData(std::ostream& stream) const
{
  stream << "radius : " << radius_ 
      << "\nframe rect height : " << frame_rect_.height
      << "\nframe rect width : " << frame_rect_.width
      << "\nposition : (" << frame_rect_.pos.x << ", " << frame_rect_.pos.y << ")\n";
}

void Circle::move(const point_t point) noexcept
{
    frame_rect_.pos = point;
}

void Circle::move(const float dx, const float dy) noexcept
{
    frame_rect_.pos.x += dx;
    frame_rect_.pos.y += dy;
}


