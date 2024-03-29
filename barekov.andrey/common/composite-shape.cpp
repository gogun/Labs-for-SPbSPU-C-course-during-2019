#include "composite-shape.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <utility>

barekov::CompositeShape::CompositeShape() :
  count_(0),
  arrayOfShapes_()
{ }

barekov::CompositeShape::CompositeShape(const CompositeShape& source) :
  count_(source.count_),
  arrayOfShapes_(new Shape*[source.count_])
{
  for (int i = 0; i < count_; i++)
  {
    arrayOfShapes_[i] = source.arrayOfShapes_[i];
  }
}

barekov::CompositeShape::CompositeShape(CompositeShape&& source) :
  count_(source.count_),
  arrayOfShapes_(std::move(source.arrayOfShapes_))
{ }

barekov::CompositeShape::CompositeShape(Shape* shape) :
  count_(1),
  arrayOfShapes_(new Shape*[1])
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Shape pointer must not be null");
  }

  arrayOfShapes_[0] = shape;
}

barekov::CompositeShape::~CompositeShape()
{
  arrayOfShapes_.reset();
  count_ = 0;
}

barekov::CompositeShape& barekov::CompositeShape::operator =(const CompositeShape& rhs)
{
  if (this != &rhs)
  {
    count_ = rhs.count_;
    std::unique_ptr<Shape*[]> tmpArray(new Shape*[rhs.count_]);
    for (int i = 0; i < count_; i++)
    {
      tmpArray[i] = rhs.arrayOfShapes_[i];
    }
    arrayOfShapes_.swap(tmpArray);
  }

  return *this;
}

barekov::CompositeShape& barekov::CompositeShape::operator =(CompositeShape&& rhs)
{
  if (this != &rhs)
  {
    count_ = rhs.count_;
    arrayOfShapes_.swap(rhs.arrayOfShapes_);
    rhs.arrayOfShapes_.reset();
    rhs.count_ = 0;
  }

  return *this;
}

double barekov::CompositeShape::getArea() const
{
  double totalArea = 0;
  for (int i = 0; i < count_; i++)
  {
    totalArea += arrayOfShapes_[i]->getArea();
  }
  return totalArea;
}

barekov::rectangle_t barekov::CompositeShape::getFrameRect() const
{
  if (count_ == 0)
  {
    return {0, 0, {0, 0}};
  }

  rectangle_t tmpFrameRect = arrayOfShapes_[0]->getFrameRect();

  //leftX, rightX, bottomY are shortened for better code readability.
  double lftX = tmpFrameRect.pos.x - tmpFrameRect.width / 2;
  double rgtX = tmpFrameRect.pos.x + tmpFrameRect.width / 2;
  double btmY = tmpFrameRect.pos.y - tmpFrameRect.height / 2;
  double topY = tmpFrameRect.pos.y + tmpFrameRect.height / 2;

  for (int i = 1; i < count_; i++)
  {
    tmpFrameRect = arrayOfShapes_[i]->getFrameRect();

    double tmpValue = tmpFrameRect.pos.x - tmpFrameRect.width / 2;
    lftX = std::min(tmpValue, lftX);

    tmpValue = tmpFrameRect.pos.x + tmpFrameRect.width / 2;
    rgtX = std::max(tmpValue, rgtX);

    tmpValue = tmpFrameRect.pos.y - tmpFrameRect.height / 2;
    btmY = std::min(tmpValue, btmY);

    tmpValue = tmpFrameRect.pos.y + tmpFrameRect.height / 2;
    topY = std::max(tmpValue, topY);
  }

  return {rgtX - lftX, topY - btmY, {(lftX + rgtX) / 2, (btmY + topY) / 2}};
}

barekov::point_t barekov::CompositeShape::getPos() const
{
  return getFrameRect().pos;
}

void barekov::CompositeShape::showScalableParameters() const
{
  std::cout << "\nFrame Rectangle size of the composite shape is "
      << getFrameRect().width << "x" << getFrameRect().height << "\n";
  for (int i = 0; i < count_; i++)
  {
    std::cout << "The position of composite shape part No." << i << " is ("
        << arrayOfShapes_[i]->getFrameRect().pos.x << "; "
        << arrayOfShapes_[i]->getFrameRect().pos.y << ")\n";
  }
}

void barekov::CompositeShape::move(const point_t& centre)
{
  const double deltaX = centre.x - getFrameRect().pos.x;
  const double deltaY = centre.y - getFrameRect().pos.y;
  for (int i = 0; i < count_; i++)
  {
    arrayOfShapes_[i]->move(deltaX, deltaY);
  }
}

void barekov::CompositeShape::move(double deltaX, double deltaY)
{
  for (int i = 0; i < count_; i++)
  {
    arrayOfShapes_[i]->move(deltaX, deltaY);
  }
}

void barekov::CompositeShape::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Composite shape scale factor must be a positive number");
  }

  const point_t centre = getFrameRect().pos;
  for (int i = 0; i < count_; i++)
  {
    const double deltaX = arrayOfShapes_[i]->getFrameRect().pos.x - centre.x;
    const double deltaY = arrayOfShapes_[i]->getFrameRect().pos.y - centre.y;
    arrayOfShapes_[i]->move({centre.x + deltaX * scaleFactor, centre.y + deltaY * scaleFactor});
    arrayOfShapes_[i]->scale(scaleFactor);
  }
}

void barekov::CompositeShape::addShape(Shape* shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Added shape pointer must not be null");
  }

  std::unique_ptr<Shape*[]> tmpArray(new Shape*[count_ + 1]);
  for (int i = 0; i < count_; i++)
  {
    tmpArray[i] = arrayOfShapes_[i];
  }
  tmpArray[count_] = shape;
  count_++;
  arrayOfShapes_.swap(tmpArray);
}

void barekov::CompositeShape::deleteShape(int index)
{
  if ((index >= count_) || (index < 0))
  {
    throw std::out_of_range("Index is out of range");
  }
  if (count_ == 0)
  {
    throw std::out_of_range("Cannot delete a figure from an empty composite shape");
  }

  for (int i = index; i < count_ - 1; i++)
  {
    arrayOfShapes_[i] = arrayOfShapes_[i + 1];
  }
  count_--;
}
