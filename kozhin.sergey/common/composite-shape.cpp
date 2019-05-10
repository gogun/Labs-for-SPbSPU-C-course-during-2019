#include "composite-shape.hpp"
#include <algorithm>
#include <stdexcept>

kozhin::CompositeShape::CompositeShape() :
  count_(0),
  size_(0),
  shapeList_(nullptr)
{
}

kozhin::CompositeShape::CompositeShape(kozhin::Shape& newShape) :
  CompositeShape()
{
  add(newShape);
}

kozhin::CompositeShape::CompositeShape(const kozhin::CompositeShape& rhs) :
  count_(rhs.count_),
  size_(rhs.size_),
  shapeList_(new kozhin::Shape*[rhs.size_])
{
  for (int i = 0; i < size_; ++i)
  {
    shapeList_[i] = rhs.shapeList_[i];
  }
}

kozhin::CompositeShape::CompositeShape(kozhin::CompositeShape&& rhs) :
  count_(rhs.count_),
  size_(rhs.size_),
  shapeList_(rhs.shapeList_)
{
  rhs.count_ = 0;
  rhs.size_ = 0;
  rhs.shapeList_ = nullptr;
}

kozhin::CompositeShape::~CompositeShape()
{
  delete[] shapeList_;
}

kozhin::CompositeShape& kozhin::CompositeShape::operator=(const kozhin::CompositeShape& rhs)
{
  if (this != &rhs)
  {
    count_ = rhs.count_;
    size_ = rhs.size_;
    delete[] shapeList_;
    shapeList_ = new kozhin::Shape*[size_];
    for (int i = 0; i < size_; ++i)
    {
      shapeList_[i] = rhs.shapeList_[i];
    }
  }
  return *this;
}

kozhin::CompositeShape& kozhin::CompositeShape::operator=(kozhin::CompositeShape&& rhs)
{
  if (this != &rhs)
  {
    count_ = rhs.count_;
    rhs.count_ = 0;

    size_ = rhs.size_;
    rhs.size_ = 0;

    delete[] shapeList_;
    shapeList_ = rhs.shapeList_;
    rhs.shapeList_ = nullptr;
  }
  return *this;
}

kozhin::Shape& kozhin::CompositeShape::operator[](int ind) const
{
  if ((ind < 0) || (ind + 1 > count_))
  {
    throw std::out_of_range("Index out of range.");
  }
  return *shapeList_[ind];
}

void kozhin::CompositeShape::add(kozhin::Shape& newShape)
{
  ++count_;
  if (count_ > size_)
  {
    kozhin::Shape** tmpList = new kozhin::Shape*[count_];
    for (int i = 0; i < size_; ++i)
    {
      tmpList[i] = shapeList_[i];
    }
    delete[] shapeList_;
    shapeList_ = tmpList;
    tmpList = nullptr;
    size_ = count_;
  }
  shapeList_[count_ - 1] = &newShape;
}

void kozhin::CompositeShape::remove(int ind)
{
  if ((ind < 0) || (ind + 1 > count_))
  {
    throw std::out_of_range("Index out of range.");
  }

  for (int i = ind + 1; i < count_; ++i)
  {
    shapeList_[i - 1] = shapeList_[i];
  }
  shapeList_[count_ - 1] = nullptr;
  --count_;
}

double kozhin::CompositeShape::getArea() const
{
  if (count_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }

  double area = 0.0;
  for (int i = 0; i < count_; ++i)
  {
    area += shapeList_[i]->getArea();
  }
  return area;
}

kozhin::rectangle_t kozhin::CompositeShape::getFrameRect() const
{
  if (count_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }

  kozhin::rectangle_t currShapeRect = shapeList_[0]->getFrameRect();

  double left = currShapeRect.pos.x - currShapeRect.width / 2;
  double right = currShapeRect.pos.x + currShapeRect.width / 2;
  double up = currShapeRect.pos.y + currShapeRect.height / 2;
  double down = currShapeRect.pos.y - currShapeRect.height / 2;

  for (int i = 1; i < count_; ++i)
  {
    currShapeRect = shapeList_[i]->getFrameRect();
    left = std::min(left, currShapeRect.pos.x - currShapeRect.width / 2);
    right = std::max(right, currShapeRect.pos.x + currShapeRect.width / 2);
    up = std::max(up, currShapeRect.pos.y + currShapeRect.height / 2);
    down = std::min(down, currShapeRect.pos.y - currShapeRect.height / 2);
  }

  return {right - left, up - down, {(left + right) / 2, (up + down) / 2}};
}

kozhin::point_t kozhin::CompositeShape::getCenter() const
{
  return getFrameRect().pos;
}

int kozhin::CompositeShape::size() const
{
  return count_;
}

void kozhin::CompositeShape::move(double dx, double dy)
{
  if (count_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }
  for (int i = 0; i < count_; ++i)
  {
    shapeList_[i]->move(dx, dy);
  }
}

void kozhin::CompositeShape::move(const point_t& point)
{
  point_t center = getCenter();
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}
void kozhin::CompositeShape::scale(double rate)
{
  if (rate <= 0)
  {
    throw std::invalid_argument("Scale rate must be positive.");
  }
  point_t center = getCenter();
  for (int i = 0; i < count_; ++i)
  {
    kozhin::point_t shapeCenter = shapeList_[i]->getCenter();
    shapeList_[i]->move((shapeCenter.x - center.x) * (rate - 1), (shapeCenter.y - center.y) * (rate - 1));
    shapeList_[i]->scale(rate);
  }
}
