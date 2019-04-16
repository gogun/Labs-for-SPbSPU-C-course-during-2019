#include "composite-shape.hpp"

#include <stdexcept>

chizhov::CompositeShape::CompositeShape(Shape* shape)
{
  if (shape == nullptr) {
    throw std::invalid_argument("Shape link cannot be nullptr");
  }

  listHead_ = new link;
  listHead_->value = shape;
  listHead_->next = nullptr;
  listHead_->prev = nullptr;
  listLast_ = listHead_;
}

chizhov::CompositeShape::CompositeShape(const chizhov::CompositeShape& source)
{
  copyFromSource(source);
}

chizhov::CompositeShape::CompositeShape(chizhov::CompositeShape&& source) :
    listHead_(source.listHead_),
    listLast_(source.listLast_)
{
  source.listHead_ = nullptr;
  source.listLast_ = nullptr;
}

chizhov::CompositeShape::~CompositeShape()
{
  while (listLast_ != nullptr) {
    link* listTmp = listLast_->prev;
    delete listLast_;
    listLast_ = listTmp;
  }
}

chizhov::CompositeShape& chizhov::CompositeShape::operator =(const chizhov::CompositeShape& rhs)
{
  if (this != &rhs) {
    copyFromSource(rhs);
  }

  return *this;
}

chizhov::CompositeShape& chizhov::CompositeShape::operator=(chizhov::CompositeShape&& rhs)
{
  if (this != &rhs) {
    listHead_ = rhs.listHead_;
    listLast_ = rhs.listLast_;

    rhs.listHead_ = nullptr;
    rhs.listLast_ = nullptr;
  }

  return *this;
}

void chizhov::CompositeShape::addShape(Shape* shape)
{
  if (shape == nullptr) {
    throw std::invalid_argument("Shape link cannot be nullptr");
  }

  listLast_->next = new link;
  listLast_->next->prev = listLast_;
  listLast_ = listLast_->next;
  listLast_->value = shape;
  listLast_->next = nullptr;
}

void chizhov::CompositeShape::deleteShape(const Shape* shape)
{
  if (shape == nullptr) {
    throw std::invalid_argument("Shape link cannot be nullptr");
  }

  if (listHead_->next == nullptr) {
    throw std::invalid_argument("You cannot destroy Composite Shape by deleting last figure");
  }

  link* listTmp = listHead_;

  while (listTmp != nullptr) {
    if (listTmp->value == shape) {
      if (listTmp == listHead_) {

        listHead_ = listTmp->next;
      }

      if (listTmp->next != nullptr) {
        listTmp->next->prev = listTmp->prev;
      }

      if (listTmp->prev != nullptr) {
        listTmp->prev->next = listTmp->next;
      }

      delete listTmp;
      return;
    }

    listTmp = listTmp->next;
  }
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
  link* listTmp = listHead_;

  while (listTmp != nullptr) {
    listTmp->value->move(dx, dy);
    listTmp = listTmp->next;
  }
}

void chizhov::CompositeShape::move(chizhov::point_t position)
{
  rectangle_t frameRect = recomputeFrame();
  double dx = position.x - frameRect.pos.x;
  double dy = position.y - frameRect.pos.y;

  link* listTmp = listHead_;

  while (listTmp != nullptr) {
    listTmp->value->move(dx, dy);
    listTmp = listTmp->next;
  }
}

void chizhov::CompositeShape::scale(double scale)
{
  if (scale <= 0) {
    throw std::invalid_argument("You cannot scale by non-positive multiplier");
  }

  rectangle_t frameRect = recomputeFrame();

  link* listTmp = listHead_;

  while (listTmp != nullptr) {
    double dx = listTmp->value->getFrameRect().pos.x - frameRect.pos.x;
    double dy = listTmp->value->getFrameRect().pos.y - frameRect.pos.y;
    listTmp->value->move(point_t{frameRect.pos.x + dx * scale, frameRect.pos.y + dy * scale});
    listTmp->value->scale(scale);
    listTmp = listTmp->next;
  }
}

double chizhov::CompositeShape::recomputeArea() const
{
  double area = 0;
  link* listTmp = listHead_;

  while (listTmp != nullptr) {
    area += listTmp->value->getArea();
    listTmp = listTmp->next;
  }

  return area;
}

chizhov::rectangle_t chizhov::CompositeShape::recomputeFrame() const
{
  link* listTmp = listHead_->next;
  rectangle_t rectTmp = listHead_->value->getFrameRect();
  double minX = rectTmp.pos.x - rectTmp.width / 2;
  double maxX = rectTmp.pos.x + rectTmp.width / 2;
  double minY = rectTmp.pos.y - rectTmp.height / 2;
  double maxY = rectTmp.pos.y + rectTmp.height / 2;

  while (listTmp != nullptr) {
    rectTmp = listTmp->value->getFrameRect();

    double tmp = rectTmp.pos.x - rectTmp.width / 2;
    minX = tmp < minX ? tmp : minX;

    tmp = rectTmp.pos.x + rectTmp.width / 2;
    maxX = tmp > maxX ? tmp : maxX;

    tmp = rectTmp.pos.y - rectTmp.height / 2;
    minY = tmp < minY ? tmp : minY;

    tmp = rectTmp.pos.y - rectTmp.height / 2;
    maxY = tmp > maxY ? tmp : maxY;

    listTmp = listTmp->next;
  }

  return  rectangle_t{maxX - minX, maxY - minY, point_t{(maxX + minX) / 2, (maxY + minY) / 2}};
}

void chizhov::CompositeShape::copyFromSource(const chizhov::CompositeShape& source)
{
  link* listTmpSource = source.listHead_;
  listHead_ = new link;
  link* listTmp = listHead_;

  while (listTmpSource->next != nullptr) {
    listTmp->value = listTmpSource->value;
    listTmp->next = new link;
    listTmp->next->prev = listTmp;

    listTmp = listTmp->next;
    listTmp->next = nullptr;
    listTmpSource = listTmpSource->next;
  }

  listTmp->value = listTmpSource->value;
  listLast_ = listTmp;
}
