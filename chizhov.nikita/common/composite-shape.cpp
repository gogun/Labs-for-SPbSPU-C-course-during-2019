#include "composite-shape.hpp"

#include <stdexcept>

chizhov::CompositeShape::CompositeShape(Shape& shape)
{
  listHead_ = new link;
  listHead_->value = &shape;
  listHead_->next = nullptr;
  listHead_->prev = nullptr;
  listLast_ = listHead_;
  frameRect_ = shape.getFrameRect();
  area_ = shape.getArea();
}

chizhov::CompositeShape::CompositeShape(const chizhov::CompositeShape& source) :
    frameRect_(source.frameRect_),
    area_(source.area_)
{
  copyFromSource(source);
}

chizhov::CompositeShape::CompositeShape(chizhov::CompositeShape&& source) :
    frameRect_(source.frameRect_),
    area_(source.area_),
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
    frameRect_ = rhs.frameRect_;
    area_ = rhs.area_;

    copyFromSource(rhs);
  }

  return *this;
}

chizhov::CompositeShape& chizhov::CompositeShape::operator=(chizhov::CompositeShape&& rhs)
{
  if (this != &rhs) {
    frameRect_ = rhs.frameRect_;
    area_ = rhs.area_;
    listHead_ = rhs.listHead_;
    listLast_ = rhs.listLast_;

    rhs.listHead_ = nullptr;
    rhs.listLast_ = nullptr;
  }

  return *this;
}

void chizhov::CompositeShape::addShape(Shape& shape)
{
  listLast_->next = new link;
  listLast_->next->prev = listLast_;
  listLast_ = listLast_->next;
  listLast_->value = &shape;
  listLast_->next = nullptr;

  recomputeFrame();
  area_ += shape.getArea();
}

double chizhov::CompositeShape::getArea() const
{
  return area_;
}

chizhov::rectangle_t chizhov::CompositeShape::getFrameRect() const
{
  return frameRect_;
}

void chizhov::CompositeShape::move(double dx, double dy)
{
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;

  link* listTmp = listHead_;

  while (listTmp != nullptr) {
    listTmp->value->move(dx, dy);
    listTmp = listTmp->next;
  }

  recomputeFrame();
}

void chizhov::CompositeShape::move(chizhov::point_t position)
{
  double dx = frameRect_.pos.x - position.x;
  double dy = frameRect_.pos.y - position.y;
  frameRect_.pos = position;

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

  frameRect_.width *= scale;
  frameRect_.height *= scale;

  link* listTmp = listHead_;

  while (listTmp != nullptr) {
    double dx = listTmp->value->getFrameRect().pos.x - frameRect_.pos.x;
    double dy = listTmp->value->getFrameRect().pos.y - frameRect_.pos.y;
    listTmp->value->move(point_t{frameRect_.pos.x + dx * scale, frameRect_.pos.y + dy * scale});
    listTmp->value->scale(scale);
    listTmp = listTmp->next;
  }

  recomputeFrame();
  recomputeArea();
}

void chizhov::CompositeShape::recomputeArea()
{
  area_ = 0;
  link* listTmp = listHead_;

  while (listTmp != nullptr) {
    area_ += listTmp->value->getArea();
    listTmp = listTmp->next;
  }
}

void chizhov::CompositeShape::recomputeFrame()
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

  frameRect_.width = maxX - minX;
  frameRect_.height = maxY - minY;
  frameRect_.pos.x = (maxX + minX) / 2;
  frameRect_.pos.y = (maxY + minY) / 2;
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
