#include "composite-shape.hpp"

#include <stdexcept>
#include <algorithm>

chizhov::CompositeShape::CompositeShape(const chizhov::CompositeShape& source) :
    quantity_(source.quantity_)
{
  copyFromSource(source);
}

chizhov::CompositeShape::CompositeShape(chizhov::CompositeShape&& source) :
    shapes_(source.shapes_),
    quantity_(source.quantity_)
{
  source.shapes_ = nullptr;
}

chizhov::CompositeShape::CompositeShape(Shape& shape) :
    quantity_(1)
{
  shapes_ = new Shape* [quantity_];
  shapes_[0] = &shape;
}

chizhov::CompositeShape::~CompositeShape()
{
  delete [] shapes_;
}

chizhov::CompositeShape& chizhov::CompositeShape::operator =(const chizhov::CompositeShape& rhs)
{
  if (this != &rhs) {
    quantity_ = rhs.quantity_;
    copyFromSource(rhs);
  }

  return *this;
}

chizhov::CompositeShape& chizhov::CompositeShape::operator =(chizhov::CompositeShape&& rhs)
{
  if (this != &rhs) {
    shapes_ = rhs.shapes_;
    quantity_ = rhs.quantity_;
    rhs.shapes_ = nullptr;
  }

  return *this;
}

double chizhov::CompositeShape::getArea() const
{
  return recomputeArea();
}

chizhov::rectangle_t chizhov::CompositeShape::getFrameRect() const
{
  return recomputeFrame();
}

void chizhov::CompositeShape::move(double dx, double dy)
{
  for (int i = 0; i < quantity_; i++) {
    shapes_[i]->move(dx, dy);
  }
}

void chizhov::CompositeShape::move(chizhov::point_t position)
{
  rectangle_t frameRect = recomputeFrame();
  double dx = position.x - frameRect.pos.x;
  double dy = position.y - frameRect.pos.y;

  for (int i = 0; i < quantity_; i++) {
    shapes_[i]->move(dx, dy);
  }
}

void chizhov::CompositeShape::scale(double scale)
{
  if (scale <= 0) {
    throw std::invalid_argument("You cannot scale by non-positive multiplier");
  }

  rectangle_t frameRect = recomputeFrame();

  for (int i = 0; i < quantity_; i++) {
    double dx = shapes_[i]->getFrameRect().pos.x - frameRect.pos.x;
    double dy = shapes_[i]->getFrameRect().pos.y - frameRect.pos.y;
    shapes_[i]->move(point_t{frameRect.pos.x + dx * scale, frameRect.pos.y + dy * scale});
    shapes_[i]->scale(scale);
  }
}

void chizhov::CompositeShape::addShape(Shape& shape)
{
  for (int i = 0; i < quantity_; i++) {
    if (shapes_[i] == &shape) {
      return;
    }
  }

  Shape** shapesArr = new Shape* [++quantity_];

  for (int i = 0; i < quantity_ - 1; i++) {
    shapesArr[i] = shapes_[i];
  }

  shapesArr[quantity_ - 1] = &shape;
  delete [] shapes_;
  shapes_ = shapesArr;
}

void chizhov::CompositeShape::deleteShape(const Shape& shape)
{
  if (quantity_ == 1) {
    throw std::invalid_argument("You cannot destroy Composite Shape by deleting last figure");
  }

  int j = 0;
  bool removed = false;
  for (int i = 0; i < quantity_; i++) {
    if (shapes_[i] == &shape) {
      removed = true;
      continue;
    }

    shapes_[j] = shapes_[i];
    j++;
  }

  if (removed) {
    shapes_[--quantity_] = nullptr;
  }
}

double chizhov::CompositeShape::recomputeArea() const
{
  double area = 0;
  for (int i = 0; i < quantity_; i++) {
    area += shapes_[i]->getArea();
  }

  return area;
}

chizhov::rectangle_t chizhov::CompositeShape::recomputeFrame() const
{
  rectangle_t rectTmp = shapes_[0]->getFrameRect();
  double minX = rectTmp.pos.x - rectTmp.width / 2;
  double maxX = rectTmp.pos.x + rectTmp.width / 2;
  double minY = rectTmp.pos.y - rectTmp.height / 2;
  double maxY = rectTmp.pos.y + rectTmp.height / 2;

  if (quantity_ == 1) {
    return  rectangle_t{maxX - minX, maxY - minY, point_t{(maxX + minX) / 2, (maxY + minY) / 2}};
  }

  for (int i = 1; i < quantity_; i++) {
    rectTmp = shapes_[i]->getFrameRect();

    double tmp = rectTmp.pos.x - rectTmp.width / 2;
    minX = std::min(tmp, minX);

    tmp = rectTmp.pos.x + rectTmp.width / 2;
    maxX = std::max(tmp, maxX);

    tmp = rectTmp.pos.y - rectTmp.height / 2;
    minY = std::min(tmp, minY);

    tmp = rectTmp.pos.y - rectTmp.height / 2;
    maxY = std::max(tmp, maxY);
  }

  return  rectangle_t{maxX - minX, maxY - minY, point_t{(maxX + minX) / 2, (maxY + minY) / 2}};
}

void chizhov::CompositeShape::copyFromSource(const chizhov::CompositeShape& source)
{
  Shape** shapesArr = new Shape* [quantity_];
  shapes_ = shapesArr;

  for (int i = 0; i < quantity_; i++) {
    shapes_[i] = source.shapes_[i];
  }
}
