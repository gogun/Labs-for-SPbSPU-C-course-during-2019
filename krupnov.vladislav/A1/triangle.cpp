#include "triangle.hpp"
#include <cmath>
#include <algorithm>

Triangle::Triangle(const point_t &top1, const point_t &top2, const point_t &top3):
  tops_({top1, top2, top3}),
  center_({(top1.x + top2.x + top3.x) / 3, (top1.y + top2.y + top3.y) / 3})
{
  if (getArea() <= 0.0) {
    throw std::invalid_argument("The specified triangle's tops is not valid.");
  }
}

void Triangle::printInfo() const
{
  std::cout << "\nTriangle";
  for (int index = 0; index < 3; index++)
  {
    std::cout << "\nTops №" << index + 1 << " coordinates: " << tops_[index].x << "; " << tops_[index].y;
  }
  std::cout << "\nCenter: " << center_.x << "; " << center_.y;
}

double Triangle::getArea() const
{
  return (0.5 * (fabs(tops_[0].x - tops_[2].x) * (tops_[1].y - tops_[2].y)
            - fabs(tops_[1].x - tops_[2].x) * (tops_[0].y - tops_[2].y)));
}

rectangle_t Triangle::getFrameRect() const
{
  const double minX = std::min(std::min(tops_[0].x, tops_[1].x), tops_[2].x);
  const double maxX = std::max(std::max(tops_[0].x, tops_[1].x), tops_[2].x);
  const double minY = std::min(std::min(tops_[0].y, tops_[1].y), tops_[2].y);
  const double maxY = std::max(std::max(tops_[0].y, tops_[1].y), tops_[2].y);

  const double width = (maxX - minX);
  const double height = (maxY - minY);
  const point_t pos = {minX + width / 2, minY + height / 2};

  return {width, height, pos};
}

void Triangle::move(const point_t &newPos)
{
  const point_t offset = {newPos.x - center_.x, newPos.y - center_.y};

  move(offset.x, offset.y);
}

void Triangle::move(double dx, double dy)
{
  for (int index = 0; index < 3; index++)
  {
    tops_[index].x += dx;
    tops_[index].y += dy;
  }

  center_.x += dx;
  center_.y += dy;
}
