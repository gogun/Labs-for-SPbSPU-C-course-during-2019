#include "polygon.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

lebedev::Polygon::Polygon():
  m_qtyVertex(0),
  m_centroid({0.0, 0.0}),
  m_vertex(nullptr)
{
}

lebedev::Polygon::Polygon(std::size_t qtyVertex, lebedev::point_t *vertex):
  m_qtyVertex(qtyVertex)
{
  if (m_qtyVertex <= 2)
  {
    throw std::invalid_argument("Quantity of vertex must be more then 2");
  }
  if (vertex == nullptr)
  {
    throw std::invalid_argument("Pointer to vertex is null!!!");
  }
  else
  {
    m_vertex = new point_t[m_qtyVertex];
    for (std::size_t index = 0; index < m_qtyVertex; index++)
    {
      m_vertex[index] = vertex[index];
    }

    m_centroid = calcCentroid();
  }
}

lebedev::Polygon::Polygon(const Polygon &other):
  m_qtyVertex(other.m_qtyVertex),
  m_centroid(other.m_centroid),
  m_vertex(new lebedev::point_t [m_qtyVertex])
{
  for (std::size_t index = 0; index < m_qtyVertex; index++)
  {
    m_vertex[index] = other.m_vertex[index];
  }
}

lebedev::Polygon::Polygon(Polygon &&other):
  m_qtyVertex(other.m_qtyVertex),
  m_centroid(other.m_centroid)
{
  if (this != &other)
  {
    other.m_qtyVertex = 0;
    other.m_centroid = {0.0, 0.0};

    delete [] m_vertex;

    m_vertex = other.m_vertex;
    other.m_vertex = nullptr;
  }
}

lebedev::Polygon & lebedev::Polygon::operator =(const Polygon &other)
{
  if (this == &other)
  {
    return *this
  }
  m_qtyVertex = other.m_qtyVertex;
  m_centroid = other.m_centroid;

  delete [] m_vertex;

  m_vertex = new lebedev::point_t [other.m_qtyVertex];
  for (std:: index = 0; index < m_qtyVertex; index++)
  {
    m_vertex[index] = other.m_vertex[index];
  }
  return *this;
}

lebedev::Polygon & lebedev::Polygon::operator =(const Polygon &&other)
{
  if (this == &other)
  {
    return *this;
  }
  m_qtyVertex = other.m_qtyVertex;
  m_centroid = other.m_centroid;

  other.m_qtyVertex = 0;
  other.m_centroid = {0.0, 0.0};

  delete [] m_vertex;

  m_vertex = other.m_vertex;
  other.m_vertex = nullptr;
  return *this;
}

lebedev::Polygon::~Polygon()
{
  delete [] m_vertex;
}

lebedev::point_t lebedev::Polygon::calcCentroid() const
{
  lebedev::point_t temp_point = {0.0, 0.0};
  for (std::size_t index = 0; index < m_qtyVertex; index++)
  {
    temp_point.x += m_vertex[index].x;
    temp_point.y += m_vertex[index].y;
  }
  return {temp_point.x / m_qtyVertex, temp_point.y / m_qtyVertex};
}

void printData() const
{
  for (std::size_t index = 0; index < m_qtyVertex ; index++)
  {
    std::cout<<"Polygon's vertex №"<<index<< ".Position of vertex (X="<<m_vertex[index].x<<";";
    std::cout<<"Y="<<m_vertex[index].y <<")"<<'\n';
  }
}

double lebedev::Polygon::getArea() const
{
  double summa = 0.0;

  for (std::size_t index = 0; index < m_qtyVertex - 1; index++)
  {
    summa += m_vertex[index].x * m_vertex[index + 1].y;
    summa -= m_vertex[index + 1].x * m_vertex[index].y;
  }

  summa += m_vertex[m_qtyVertex-1].x * m_vertex[0].y;
  summa -= m_vertex[0].x * m_vertex[m_qtyVertex-1].y;

  return (0.5 * std::fabs(summa));
}

lebedev::rectangle_t lebedev::Polygon::getFrameRect() const
{
  double maxX = m_vertex[0].x;
  double minX = m_vertex[0].x;
  double maxY = m_vertex[0].y;
  double minY = m_vertex[0].y;

  for (std::size_t index = 0; index < m_qtyVertex; index++)
  {
    maxX = std::max(maxX, m_vertex[index].x);
    minX = std::min(minX, m_vertex[index].x);
    maxY = std::max(maxY, m_vertex[index].y);
    minY = std::min(minY, m_vertex[index].y);
  }

  const double width = (maxY - minY);
  const double height = (maxX - minX);
  const point_t posFrameRect = {minX + (width / 2), minY + (height / 2)};

  return {width, height, posFrameRect};
}

void lebedev::Polygon::scale(const double multiplier)
{
  if (multiplier <= 0.0)
  {
    throw std::invalid_argument("Multiplier must be more then 0.0");
  }
  else
  {
    for (std::size_t index = 0; index < m_qtyVertex; index ++)
    {
      m_vertex[index].x = m_centroid.x + (m_vertex[index].x - m_centroid.x) * multiplier;
      m_vertex[index].y = m_centroid.y + (m_vertex[index].y - m_centroid.y) * multiplier;
    }
  }
}

bool lebedev::Polygon::checkBump() const
{
  point_t side_1 = {0.0, 0.0};
  point_t side_2 = {0.0, 0.0};

  for (std::size_t index = 0; index <= m_qtyVertex - 2 ; index++)
  {
    if (index == m_qtyVertex - 2)
    {
      side_1.x = m_vertex[index + 1].x - m_vertex[index].x;
      side_1.y = m_vertex[index + 1].y - m_vertex[index].y;
      side_2.x = m_vertex[0].x - m_vertex[index + 1].x;
      side_2.y = m_vertex[0].y - m_vertex[index + 1].y;
    }
    else
    {
      side_1.x = m_vertex[index + 1].x - m_vertex[index].x;
      side_1.y = m_vertex[index + 1].y - m_vertex[index].y;
      side_2.x = m_vertex[index + 2].x - m_vertex[index + 1].x;
      side_2.y = m_vertex[index + 2].y - m_vertex[index + 1].y;
    }
    if (((side_1.x * side_2.y) - (side_1.y * side_2.x)) < 0.0)
    {
      return true;
    }
  }
  return false;
}

void lebedev::Polygon::move(const double x, const double y)
{
  for (std::size_t index = 0; index < m_qtyVertex; index++)
  {
    m_vertex[index].x += x;
    m_vertex[index].y += y;
  }
  m_centroid.x += x;
  m_centroid.y += y;
}

void lebedev::Polygon::move(const point_t &new_point)
{
  const point_t differens = {new_point.x - m_centroid.x, new_point.y - m_centroid.y};
  move(differens.x, differens.y);
}
