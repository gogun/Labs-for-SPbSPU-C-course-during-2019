#include "rectangle.hpp"

#include <stdexcept>

rodchenkov::Rectangle::Rectangle(const point_t& pos, const double height, const double width) :
  height_(height),
  width_(width),
  frame_rect_({height, width, pos})
{
  if ((height < 0) || (width < 0)) {
    throw std::invalid_argument("rectangle width and height can\'t be negative");
  }
}

double rodchenkov::Rectangle::getArea() const noexcept
{
  return height_ * width_;
}

rodchenkov::rectangle_t rodchenkov::Rectangle::getFrameRect() const noexcept
{
  return frame_rect_;
}

std::shared_ptr<rodchenkov::Shape> rodchenkov::Rectangle::cloneShared() const
{
  return std::make_shared<Rectangle>(*this);
}

void rodchenkov::Rectangle::printData(std::ostream& stream) const
{
  stream << "Shape : Rectangle\n"
      << "Position : (" << frame_rect_.pos.x << ", " << frame_rect_.pos.y << ")\n"
      << "Width : " << width_ << "\n"
      << "Height : " << height_ << "\n"
      << "Area : " << getArea() << "\n";
}

void rodchenkov::Rectangle::move(const point_t& point) noexcept
{
  frame_rect_.pos = point;
}

void rodchenkov::Rectangle::move(const double dx, const double dy) noexcept
{
  frame_rect_.pos.x += dx;
  frame_rect_.pos.y += dy;
}

void rodchenkov::Rectangle::scale(const double ratio)
{
  if (ratio < 0) {
    throw std::invalid_argument("scaling ratio can\'t be negative");
  }
  width_             *= ratio;
  height_            *= ratio;
  frame_rect_.width  *= ratio;
  frame_rect_.height *= ratio;
}

double rodchenkov::Rectangle::getWidth() const noexcept
{
  return width_;
}

double rodchenkov::Rectangle::getHeight() const noexcept
{
  return height_;
}
