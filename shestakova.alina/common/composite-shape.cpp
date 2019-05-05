#include <stdexcept>
#include "composite-shape.hpp"

shestakova::CompositeShape::CompositeShape() :
  count_(0),
  figures_()
{}

shestakova::CompositeShape::CompositeShape(const CompositeShape& copiedCompositeShape) :
  count_(copiedCompositeShape.count_),
  figures_(new Shape *[copiedCompositeShape.count_])
{
  for (unsigned int i = 0; i < count_; ++i)
  {
    figures_[i] = copiedCompositeShape.figures_[i];
  }
}

shestakova::CompositeShape::CompositeShape(CompositeShape&& movedCompositeShape) :
  count_(movedCompositeShape.count_),
  figures_(movedCompositeShape.figures_)
{
    movedCompositeShape.figures_ = nullptr;
    movedCompositeShape.count_ = 0;
}

shestakova::CompositeShape::CompositeShape(Shape& shape) :
  count_(1),
  figures_(new Shape*[1])
{
   figures_[0] = &shape;
}

shestakova::CompositeShape::~CompositeShape()
{
  delete [] figures_;
}

shestakova::CompositeShape &shestakova::CompositeShape::operator =(const CompositeShape &copiedCompositeShape)
{
  if (this != &copiedCompositeShape)
  {
    delete [] figures_;
    count_ = copiedCompositeShape.count_;
    figures_ = new Shape*[copiedCompositeShape.count_];
    for (unsigned int i = 0; i < count_; i++)
    {
      figures_[i] = copiedCompositeShape.figures_[i];
    }
  }
  return *this;
}

shestakova::CompositeShape &shestakova::CompositeShape::operator =(CompositeShape &&movedCompositeShape)
{
  if (this != &movedCompositeShape)
  {
    count_ = movedCompositeShape.count_;
    figures_ = movedCompositeShape.figures_;
    movedCompositeShape.figures_ = nullptr;
    movedCompositeShape.count_ = 0;
  }
  return *this;
}

shestakova::Shape *shestakova::CompositeShape::operator [](unsigned int index) const
{
  if (index >= count_)
  {
    throw std::out_of_range("Index out of range");
  }

  return figures_[index];
}

double shestakova::CompositeShape::getArea() const
{
  double area = 0;
  for (unsigned int i = 0; i < count_; i++)
  {
    area += figures_[i]->getArea();
  }
  return area;
}

shestakova::rectangle_t shestakova::CompositeShape::getFrameRect() const
{
  if (count_ == 0)
  {
    throw std::logic_error("Composite shape is empty!");
  }

  shestakova::rectangle_t tmpShape = figures_[0]->getFrameRect();
  double minX = tmpShape.pos.x - tmpShape.width / 2;
  double minY = tmpShape.pos.y - tmpShape.height / 2;
  double maxX = tmpShape.pos.x + tmpShape.width / 2;
  double maxY = tmpShape.pos.y + tmpShape.height / 2;

  for (unsigned int i = 0; i < count_; i++)
  {
    tmpShape = figures_[i]->getFrameRect();
    double tmpValue = tmpShape.pos.x - tmpShape.width / 2;
    minX = std::min(tmpValue, minX);
    tmpValue = tmpShape.pos.y - tmpShape.height / 2;
    minY = std::min(tmpValue, minY);
    tmpValue = tmpShape.pos.x + tmpShape.width / 2;
    maxX = std::max(tmpValue, maxX);
    tmpValue = tmpShape.pos.y + tmpShape.height / 2;
    maxY = std::max(tmpValue, maxY);
  }

  return{(maxX - minX), (maxY - minY), {(maxX + minX) / 2, (maxY + minY) / 2}};
}

void shestakova::CompositeShape::move(const point_t &point)
{
  point_t frameRectPos = getFrameRect().pos;
  double dx = point.x - frameRectPos.x;
  double dy = point.y - frameRectPos.y;

  move(dx, dy);
}

void shestakova::CompositeShape::move(double dx, double dy)
{
  if (count_ == 0)
  {
    throw std::logic_error("Composite shape is empty!");
  }

  for (unsigned int i = 0; i < count_; i++)
  {
    figures_[i]->move(dx, dy);
  }
}

void shestakova::CompositeShape::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient can't be negative.");
  }

  shestakova::point_t frameRectPos = getFrameRect().pos;
  for (unsigned int i = 0; i < count_; i++)
  {
    shestakova::point_t shapeCenter = figures_[i]->getFrameRect().pos;
    double dx = (shapeCenter.x - frameRectPos.x) * (coefficient - 1);
    double dy = (shapeCenter.y - frameRectPos.y) * (coefficient - 1);
    figures_[i]->move(dx, dy);
    figures_[i]->scale(coefficient);
  }
}

void shestakova::CompositeShape::addShape(Shape &shape)
{
  Shape** shapesArray = new Shape *[count_ + 1];
  for(unsigned int i = 0; i < count_; i++)
  {
    shapesArray[i] = figures_[i];
  }
  shapesArray[count_] = &shape;
  count_++;
  delete[] figures_;
  figures_ = shapesArray;
}

void shestakova::CompositeShape::deleteShape(unsigned int index)
{
  if (index >= count_)
  {
    throw std::invalid_argument("Index out of range");
  }
  count_--;
  for (unsigned int i = index; i < count_; i++)
  {
    figures_[i] = figures_[i + 1];
  }
}

