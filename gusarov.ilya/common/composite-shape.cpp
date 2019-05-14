#include "composite-shape.hpp"
#include <iostream>
#include <stdexcept>

gusarov::CompositeShape::CompositeShape():
  size_(0),
  shapes_(nullptr)
{
}
gusarov::CompositeShape::CompositeShape(const gusarov::CompositeShape& newShape):
  size_(newShape.size_),
  shapes_(new gusarov::Shape* [size_])
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i] = newShape.shapes_[i];
  }

}
gusarov::CompositeShape::CompositeShape(gusarov::CompositeShape&& newShape):
  size_(newShape.size_),
  shapes_(newShape.shapes_)
{
  newShape.size_ = 0;
  newShape.shapes_ = nullptr;
}
gusarov::CompositeShape::CompositeShape(gusarov::Shape& newShape):
  CompositeShape()
{
  add(newShape);
}
gusarov::CompositeShape::~CompositeShape()
{
  delete [] shapes_;
}

gusarov::CompositeShape& gusarov::CompositeShape::operator =(const gusarov::CompositeShape& newShape)
{
  if (&newShape == this)
  {
    return* this;
  }
  size_ = newShape.size_;
  delete [] shapes_;
  shapes_ = new Shape* [size_];
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i] = newShape.shapes_[i];
  }
  return* this;
}
gusarov::CompositeShape& gusarov::CompositeShape::operator =(gusarov::CompositeShape&& newShape)
{

  if (&newShape == this)
  {
    return* this;
  }
  size_ = newShape.size_;
  newShape.size_ = 0;

  delete [] shapes_;
  shapes_ = newShape.shapes_;
  newShape.shapes_ = nullptr;

  return* this;
}
gusarov::Shape& gusarov::CompositeShape::operator [](const size_t index) const
{
  if (index + 1 > size_)
  {
     throw std::out_of_range("Index is out of range");
  }
  return* shapes_[index];
}
size_t gusarov::CompositeShape::getSize() const
{
  return size_;
}
void gusarov::CompositeShape::add(gusarov::Shape& newShape)
{
  ++size_;
  gusarov::Shape** tmpShapes = new gusarov::Shape* [size_];
  for (size_t i = 0; i < size_ - 1; ++i)
  {
    tmpShapes[i] = shapes_[i];
  }
  delete [] shapes_;
  shapes_ = tmpShapes;
  tmpShapes = nullptr;
  shapes_[size_ - 1] = &newShape;
}
void gusarov::CompositeShape::remove(size_t index)
{
  if (index + 1 > size_)
  {
    throw std::out_of_range("Index is out of range");
  }
  --size_;
  gusarov::Shape** tmpShapes = new gusarov::Shape* [size_];
  for (size_t i = 0; i < index; ++i)
  {
    tmpShapes[i] = shapes_[i];
  }
  for (size_t i = index + 1; i < size_ + 1; ++i)
  {
    tmpShapes[i - 1] = shapes_[i];
  }
  delete [] shapes_;
  shapes_ = tmpShapes;
  tmpShapes = nullptr;
}
double gusarov::CompositeShape::getArea() const
{
  if (size_ == 0)
  {
    throw std::logic_error("There is nothing in composite shape");
  }
  double area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}
gusarov::rectangle_t gusarov::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    throw std::logic_error("There is nothing in composite shape");
  }
  gusarov::rectangle_t frameRect = shapes_[0]->getFrameRect();
  double minX = frameRect.pos.x - frameRect.width / 2;
  double maxX = frameRect.pos.x + frameRect.width / 2;
  double minY = frameRect.pos.y - frameRect.height / 2;
  double maxY = frameRect.pos.y + frameRect.height / 2;

  for (size_t i = 1; i < size_; ++i)
  {
    frameRect = shapes_[i]->getFrameRect();

    minX = std::min(frameRect.pos.x - frameRect.width / 2, minX);
    maxX = std::max(frameRect.pos.x + frameRect.width / 2, maxX);
    minY = std::min(frameRect.pos.y - frameRect.height / 2, minY);
    maxY = std::max(frameRect.pos.y - frameRect.height / 2, maxY);
  }
  return {(maxX - minX), (maxY - minY), {(maxX + minX) / 2, (maxY + minY) / 2}};
}
void gusarov::CompositeShape::move(const double shiftX, const double shiftY)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i]->move(shiftX, shiftY);
  }
}
void gusarov::CompositeShape::move(const gusarov::point_t& newPoint)
{
  gusarov::rectangle_t frameRect = getFrameRect();
  double shiftX = newPoint.x - frameRect.pos.x;
  double shiftY = newPoint.y - frameRect.pos.y;
  move(shiftX, shiftY);
}
void gusarov::CompositeShape::printInfo() const
{
  std::cout << "Width of composite shape is " << getFrameRect().width << '\n';
  std::cout << "Height of composite shape is " << getFrameRect().height << '\n';
  std::cout << "Center of composite shape is a point: (" << getFrameRect().pos.x << ";" << getFrameRect().pos.y << ")" << '\n';
  std::cout << "Number of shapes in composite shape is " << size_ << '\n';
}
void gusarov::CompositeShape::scale(const double scale)
{
  if (scale <= 0.0)
  {
    throw std::invalid_argument("Invalid scale value");
  }
  gusarov::point_t frameRectPos = getFrameRect().pos;
  double centerScaleX = 0.0;
  double centerScaleY = 0.0;

  for (size_t i = 0; i < size_; ++i)
  {
    centerScaleX = shapes_[i]->getFrameRect().pos.x - frameRectPos.x;
    centerScaleY = shapes_[i]->getFrameRect().pos.y - frameRectPos.y;
    shapes_[i]->move({centerScaleX * scale + frameRectPos.x, centerScaleY * scale + frameRectPos.y});
    shapes_[i]->scale(scale);
  }
}
