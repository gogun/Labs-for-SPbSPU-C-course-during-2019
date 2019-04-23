#include "polygon.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

lebedev::Polygon::Polygon(std::size_t qtyVertex, lebedev::point_t *vertex):
  m_qtyVertex(qtyVertex)
{
  if (m_qtyVertex <= 2)
  {
    throw std::invalid_argument("Quantity of vertex must be more then 2");
  }

  m_vertex = new point_t[m_qtyVertex];
  for (std::size_t index = 0; index < m_qtyVertex; index ++)
  {
    m_vertex[index] = vertex[index];
  }

  m_centroid = calcCentroid();
}

lebedev::Polygon::~Polygon()
{
  delete [] m_vertex;
}

lebedev::point_t lebedev::Polygon::calcCentroid() const
{
  lebedev::point_t temp_point = {0.0, 0.0};
  for (std::size_t index = 0; index < m_qtyVertex; index ++)
  {
    temp_point.x += m_vertex[index].x;
    temp_point.y += m_vertex[index].y;
  }
  return {temp_point.x / m_qtyVertex, temp_point.y / m_qtyVertex};
}

void lebedev::Polygon::printData() const
{
  for (std::size_t index = 1; index < m_qtyVertex + 1; index ++)
  {
    std::cout<<"Polygon's vertex №"<<index<< ".Position of vertex (X="<<m_vertex[index - 1].x<<";";
    std::cout<<"Y="<<m_vertex[index - 1].y <<")"<<'\n';
  }
}

double lebedev::Polygon::getArea() const
{
  double summa = 0.0;

  for (std::size_t index = 0; index < m_qtyVertex - 1; index ++)
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
  point_t max = {m_vertex[1].x, m_vertex[1].y};
  point_t min = {m_vertex[1].x, m_vertex[1].y};

  for (std::size_t index = 0; index < m_qtyVertex; index ++)
  {
    if (max.x < m_vertex[index].x)
    {
      max.x = m_vertex[index].x;
    }
    if (max.y < m_vertex[index].y)
    {
      max.y = m_vertex[index].y;
    }
    if (min.x > m_vertex[index].x)
    {
      min.x = m_vertex[index].x;
    }
    if (min.y > m_vertex[index].y)
    {
      min.y = m_vertex[index].y;
    }
  }
  const point_t posFrameRect = calcCentroid();
  const double width = (max.y - min.y);
  const double height = (max.x - min.x);
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
  std::size_t status = m_qtyVertex;
  point_t side_1, side_2;
  side_1 = side_2 = {0.0, 0.0};

  for (std::size_t index = m_qtyVertex; index < 1; index --)
  {
    if (index == 1)
    {
      side_1.x = m_vertex[index].x - m_vertex[index - 1].x;
      side_1.y = m_vertex[index].y - m_vertex[index - 1].y;
      side_2.x = m_vertex[index - 1].x - m_vertex[m_qtyVertex].x;
      side_2.y = m_vertex[index - 1].y - m_vertex[m_qtyVertex].y;
    }
    else
    {
      side_1.x = m_vertex[index].x - m_vertex[index - 1].x;
      side_1.y = m_vertex[index].y - m_vertex[index - 1].y;
      side_2.x = m_vertex[index - 1].x - m_vertex[index - 2].x;
      side_2.y = m_vertex[index - 1].y - m_vertex[index - 2].y;
      status += 1;
    }
    double flag = ((side_1.x * side_2.y) - (side_1.y * side_2.x));
    if (flag < 0)
    {
      status -= 1;
    }
  }
  if (status != 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void lebedev::Polygon::move(const double x, const double y)
{
  for (std::size_t index = 0; index < m_qtyVertex; index ++)
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
