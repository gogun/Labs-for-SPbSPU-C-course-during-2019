#include "composite-shape.hpp"

#include <stdexcept>

chizhov::CompositeShape::CompositeShape(Shape *shape)
{
  if (shape != nullptr) {
    listHead_ = new link;
    listHead_->value = shape;
    listHead_->next = nullptr;
    listHead_->prev = nullptr;
    listLast_ = listHead_;
    frameRect_ = shape->getFrameRect();
    area_ = shape->getArea();
  } else {
    throw std::invalid_argument("Shape cannot be null");
  }
}

chizhov::CompositeShape::~CompositeShape()
{
  link* listTmp;
  do {
    listTmp = listLast_->prev;
    delete listLast_;
    listLast_ = listTmp;
  } while (listLast_ != nullptr);
}

void chizhov::CompositeShape::addShape(Shape* shape)
{
  if (shape != nullptr) {
    listLast_->next = new link;
    listLast_->next->prev = listLast_;
    listLast_ = listLast_->next;
    listLast_->value = shape;
    listLast_->next = nullptr;

    recomputeFrame();
    area_ += shape->getArea();
  } else {
    throw std::invalid_argument("Shape cannot be null");
  }
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

  do {
    listTmp->value->move(dx, dy);
    listTmp = listTmp->next;
  } while (listTmp != nullptr);

  recomputeFrame();
}

void chizhov::CompositeShape::move(chizhov::point_t position)
{
  double dx = frameRect_.pos.x - position.x;
  double dy = frameRect_.pos.y - position.y;
  frameRect_.pos = position;

  link* listTmp = listHead_;

  do {
    listTmp->value->move(dx, dy);
    listTmp = listTmp->next;
  } while (listTmp != nullptr);
}

void chizhov::CompositeShape::scale(double scale)
{
  frameRect_.width *= scale;
  frameRect_.height *= scale;

  link* listTmp = listHead_;

  do {
    double dx = listTmp->value->getFrameRect().pos.x - frameRect_.pos.x;
    double dy = listTmp->value->getFrameRect().pos.y - frameRect_.pos.y;
    listTmp->value->move(point_t{frameRect_.pos.x + dx * scale, frameRect_.pos.y + dy * scale});
    listTmp->value->scale(scale);
    listTmp = listTmp->next;
  } while (listTmp != nullptr);

  recomputeFrame();
  recomputeArea();
}

void chizhov::CompositeShape::recomputeArea()
{
  area_ = 0;
  link* listTmp = listHead_;

  do {
    area_ += listTmp->value->getArea();
    listTmp = listTmp->next;
  } while (listTmp != nullptr);
}

void chizhov::CompositeShape::recomputeFrame()
{
  link* listTmp = listHead_->next;
  rectangle_t rectTmp = listHead_->value->getFrameRect();
  double minX = rectTmp.pos.x - rectTmp.width / 2;
  double maxX = rectTmp.pos.x + rectTmp.width / 2;
  double minY = rectTmp.pos.y - rectTmp.height / 2;
  double maxY = rectTmp.pos.y + rectTmp.height / 2;

  do {
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
  } while (listTmp != nullptr);

  frameRect_.width = maxX - minX;
  frameRect_.height = maxY - minY;
  frameRect_.pos.x = (maxX + minX) / 2;
  frameRect_.pos.y = (maxY + minY) / 2;
}
