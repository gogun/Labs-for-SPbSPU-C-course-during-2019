#include "composite-shape.hpp"
#include <cmath>

rodchenkov::CompositeShape::CompositeShape() :
  size_(0),
  frame_rect_({0, 0, {0, 0}})
{
}

rodchenkov::CompositeShape::CompositeShape(const CompositeShape& cs)
{
  size_       = cs.size_;
  frame_rect_ = cs.frame_rect_;
  shapes_     = std::make_unique<std::shared_ptr<Shape>[]>(size_);
  for (std::size_t i = 0; i < size_; i++) {
    shapes_[i] = cs.shapes_[i]->cloneShared();
  }
}

rodchenkov::CompositeShape::CompositeShape(CompositeShape&& cs) noexcept
{
  size_       = cs.size_;
  frame_rect_ = cs.frame_rect_;
  shapes_.swap(cs.shapes_);
}

const rodchenkov::CompositeShape& rodchenkov::CompositeShape::operator=(const CompositeShape& cs)
{
  CompositeShape temp(cs);
  swap(*this, temp);
  return *this;
}

const rodchenkov::CompositeShape& rodchenkov::CompositeShape::operator=(CompositeShape&& cs) noexcept
{
  swap(*this, cs);
  return *this;
}

double rodchenkov::CompositeShape::getArea() const noexcept
{
  double area = 0.0;
  for (std::size_t i = 0; i < size_; i++) {
    area += shapes_[i]->getArea();
  }
  return area;
}

rodchenkov::rectangle_t rodchenkov::CompositeShape::getFrameRect() const noexcept
{
  return frame_rect_;
}

void rodchenkov::CompositeShape::printData(std::ostream& stream) const
{
  stream << "Shape : Composite shape\n"
      << "Position : (" << frame_rect_.pos.x << ", " << frame_rect_.pos.y << ")\n"
      << "Width : " << frame_rect_.width << "\n"
      << "Height : " << frame_rect_.height << "\n"
      << "Area : " << getArea() << "\n"
      << "Number of shapes : " << size_ << "\n";
}

void rodchenkov::CompositeShape::move(const point_t& point) noexcept
{
  move(point.x - frame_rect_.pos.x, point.y - frame_rect_.pos.y);
}

void rodchenkov::CompositeShape::move(const double dx, const double dy) noexcept
{
  frame_rect_.pos.x += dx;
  frame_rect_.pos.y += dy;
  for (std::size_t i = 0; i < size_; i++) {
    shapes_[i]->move(dx, dy);
  }
}

void rodchenkov::CompositeShape::scale(const double ratio)
{
  if (ratio >= 0) {
    frame_rect_.width *= ratio;
    frame_rect_.height *= ratio;
    for (std::size_t i = 0; i < size_; i++) {
      point_t currPose  = shapes_[i]->getFrameRect().pos;
      double  relativeX = currPose.x - frame_rect_.pos.x;
      double  relativeY = currPose.y - frame_rect_.pos.y;
      double  dx        = relativeX * (ratio - 1);
      double  dy        = relativeY * (ratio - 1);
      shapes_[i]->scale(ratio);
      shapes_[i]->move(dx, dy);
    }
  } else {
    throw std::invalid_argument("scaling ratio can\'t be negative");
  }
}

void rodchenkov::CompositeShape::add(const std::shared_ptr<Shape>& newShape)
{
  if (newShape) {
    std::unique_ptr<std::shared_ptr<Shape>[]> newShapes = std::make_unique<std::shared_ptr<Shape>[]>(size_ + 1);
    for (std::size_t = 0; i < size_; i++) {
      newShapes[i] = shapes_[i];
    }
    newShapes[size_++] = newShape;
    shapes_.swap(newShapes);
    if (size_ > 1) {
      computeFrameRect();
    } else {
      frame_rect_ = newShape->getFrameRect();
    }
  } else {
    throw std::invalid_argument("new shape pointer can\'t be null");
  }
}

std::size_t rodchenkov::CompositeShape::getSize() const noexcept
{
  return size_;
}

std::shared_ptr<rodchenkov::Shape> rodchenkov::CompositeShape::cloneShared() const
{
  return std::make_shared<CompositeShape>(*this);
}

void rodchenkov::CompositeShape::computeFrameRect() noexcept
{
  double left   = frame_rect_.pos.x - frame_rect_.width / 2;
  double right  = frame_rect_.pos.x + frame_rect_.width / 2;
  double top    = frame_rect_.pos.y + frame_rect_.height / 2;
  double bottom = frame_rect_.pos.y - frame_rect_.height / 2;
  for (std::size_t i = 0; i < size_; i++) {
    const rectangle_t currRect = shapes_[i]->getFrameRect();

    double currLeft   = currRect.pos.x - currRect.width / 2;
    double currRight  = currRect.pos.x + currRect.width / 2;
    double currTop    = currRect.pos.y + currRect.height / 2;
    double currBottom = currRect.pos.y - currRect.height / 2;

    if (currLeft < left) {
      left = currLeft;
    }
    if (currRight > right) {
      right = currRight;
    }
    if (currTop > top) {
      top = currTop;
    }
    if (currBottom < bottom) {
      bottom = currBottom;
    }
  }
  frame_rect_ = {fabs(top - bottom), fabs(right - left), {(left + right) / 2, (top + bottom) / 2}};
}

void rodchenkov::swap(CompositeShape& l, CompositeShape& r) noexcept
{
  std::swap(l.size_, r.size_);
  std::swap(l.frame_rect_, r.frame_rect_);
  l.shapes_.swap(r.shapes_);
}
