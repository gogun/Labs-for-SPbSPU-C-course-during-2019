#include "composite-shape.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>

rodchenkov::CompositeShape::CompositeShape() :
  count_(0)
{
}

rodchenkov::CompositeShape::CompositeShape(const CompositeShape& cs) :
  count_(cs.count_)
{
  shapes_ = std::make_unique<std::unique_ptr<Shape>[]>(count_);
  for (std::size_t i = 0; i < count_; i++) {
    shapes_[i] = cs.shapes_[i]->cloneUnique();
  }
}

rodchenkov::CompositeShape::CompositeShape(CompositeShape&& cs) noexcept :
  count_(cs.count_)
{
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

rodchenkov::Shape* rodchenkov::CompositeShape::operator [](const std::size_t n) const
{
  if (n < count_) {
    return shapes_[n].get();
  }
  throw std::out_of_range{"index was out of range in CompositeShape::operator[]"};
}

double rodchenkov::CompositeShape::getArea() const noexcept
{
  double area = 0.0;
  for (std::size_t i = 0; i < count_; i++) {
    area += shapes_[i]->getArea();
  }
  return area;
}

rodchenkov::rectangle_t rodchenkov::CompositeShape::getFrameRect() const noexcept
{
  return computeFrameRect();
}

void rodchenkov::CompositeShape::printData(std::ostream& stream) const
{
  const rectangle_t frameRect = computeFrameRect();
  stream << "Shape : Composite shape\n"
      << "Position : (" << frameRect.pos.x << ", " << frameRect.pos.y << ")\n"
      << "Width : " << frameRect.width << "\n"
      << "Height : " << frameRect.height << "\n"
      << "Area : " << getArea() << "\n"
      << "Number of shapes : " << count_ << "\n";
}

void rodchenkov::CompositeShape::move(const point_t& point) noexcept
{
  const rectangle_t frameRect = computeFrameRect();
  move(point.x - frameRect.pos.x, point.y - frameRect.pos.y);
}

void rodchenkov::CompositeShape::move(const double dx, const double dy) noexcept
{
  for (std::size_t i = 0; i < count_; i++) {
    shapes_[i]->move(dx, dy);
  }
}

void rodchenkov::CompositeShape::scale(const double ratio)
{
  if (ratio >= 0) {
    const rectangle_t frameRect = computeFrameRect();
    for (std::size_t i = 0; i < count_; i++) {
      point_t currPose  = shapes_[i]->getFrameRect().pos;
      double  relativeX = currPose.x - frameRect.pos.x;
      double  relativeY = currPose.y - frameRect.pos.y;
      double  dx        = relativeX * (ratio - 1);
      double  dy        = relativeY * (ratio - 1);
      shapes_[i]->scale(ratio);
      shapes_[i]->move(dx, dy);
    }
  } else {
    throw std::invalid_argument("scaling ratio can\'t be negative");
  }
}

void rodchenkov::CompositeShape::add(const Shape& newShape)
{
  std::unique_ptr<std::unique_ptr<Shape>[]> newShapes = std::make_unique<std::unique_ptr<Shape>[]>(count_ + 1);
  for (std::size_t i = 0; i < count_; i++) {
    newShapes[i].swap(shapes_[i]);
  }
  newShapes[count_++] = newShape.cloneUnique();
  shapes_.swap(newShapes);
}

void rodchenkov::CompositeShape::remove(const std::size_t n)
{
  if (n < count_) {
    std::unique_ptr<std::unique_ptr<Shape>[]> newShapes = std::make_unique<std::unique_ptr<Shape>[]>(count_ - 1);
    std::size_t destAdr = 0;
    for (std::size_t i = 0; i < count_; i++) {
      if (i == n) {
        continue;
      }
      newShapes[destAdr++].swap(shapes_[i]);
    }
    shapes_.swap(newShapes);
    --count_;
  } else {
    throw std::out_of_range{"index was out of range in CompositeShape::remove"};
  }
}

std::size_t rodchenkov::CompositeShape::getSize() const noexcept
{
  return count_;
}

std::unique_ptr<rodchenkov::Shape> rodchenkov::CompositeShape::cloneUnique() const
{
  return std::make_unique<CompositeShape>(*this);
}

rodchenkov::rectangle_t rodchenkov::CompositeShape::computeFrameRect() const noexcept
{
  if (count_ > 0) {
    double left   = shapes_[0]->getFrameRect().pos.x;
    double right  = shapes_[0]->getFrameRect().pos.x;
    double top    = shapes_[0]->getFrameRect().pos.y;
    double bottom = shapes_[0]->getFrameRect().pos.y;
    for (std::size_t i = 0; i < count_; i++) {
      const rectangle_t currRect = shapes_[i]->getFrameRect();

      double currLeft   = currRect.pos.x - currRect.width / 2;
      double currRight  = currRect.pos.x + currRect.width / 2;
      double currTop    = currRect.pos.y + currRect.height / 2;
      double currBottom = currRect.pos.y - currRect.height / 2;

      left   = std::min(currLeft, left);
      right  = std::max(currRight, right);
      top    = std::max(currTop, top);
      bottom = std::min(currBottom, bottom);
    }
    return {fabs(top - bottom), fabs(right - left), {(left + right) / 2, (top + bottom) / 2}};
  }
  return {0, 0, {0, 0}};
}

void rodchenkov::CompositeShape::swap(CompositeShape& l, CompositeShape& r) noexcept
{
  std::swap(l.count_, r.count_);
  std::swap(l.shapes_, r.shapes_);
}
