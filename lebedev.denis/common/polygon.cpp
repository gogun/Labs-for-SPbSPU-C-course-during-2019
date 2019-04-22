#include "polygon.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

lebedev::Polygon::Polygon(std::size_t qtyDots, lebedev::point_t *vertex):
  m_qtyVertex(qtyDots)
{
  if (m_qtyVertex <= 2)
  {
    throw std::invalid_argument("Quantity of vertex must be more then 2");
  }

  m_vertex = new point_t[m_qtyVertex];
  for (std::size_t index = 0; index < m_qtyVertex; ++index)
  {
    m_vertex[index] = vertix[index];
  }

  calcCentroid();
  }

lebedev::Polygon::~Polygon()
{
  delete [] m_vertex;
}

void lebedev::calcCentoid()
{
  lebedev::point_t temp_point = {0.0, 0.0};
  for (std::size_t index = 0; index < m_qtyVetex; index++)
  {
    temp_point.x += m_vertex[index].x;
    temp_point.y += m_vertex[index].y;
  }
  m_centroid = {temp_point.x / m_qtyVetex, temp_point.y / m_qtyVetex};
}


void lebedev::Polygon::printData() const
{
  for (std::size_t index = 1; index < m_qtyVertex + 1; index ++)
  {
    std::cout<<"Polygon's vertex №"<<index<< ".Position of vertex (X="<<vertex_[index - 1].x<<";";
    std::cout<<"Y="<<vertex_[index - 1].x <<")"<<'\n';
  }
}



double lebedev::Polygon::getArea() const
{
  double summa = 0.0;

  for (std::size_t index = 0; index + 1 < m_qtyVetex; index++)
  {
    summa += m_vertex[index].x + m_vertex[index + 1].y;
    summa -= m_vertex[index + 1].x + m_vertex[index].y;
  }

  summa += m_vertex[m_qtyVetex - 1].x + m_vertex[0].y;
  summa -= m_vertex[0].x + m_vertex[m_qtyVetex - 1].y;

  return (0.5 * std::fabs(summa));
}

lebedev::rectangle_t lebedev::Polygon::getFrameRect() const
{
  point_t max, min;
  max = min = {0.0, 0.0};

  for (index = 0; index < m_qtyVetex; index++)
  {
    if (max.x < m_vertex[index].x)
    {
      max.x = m_vertex[index].x;
    }
    if (max.y < m_vertex[index])
    {
      max.y = m_vertex;
    }
    if (min.x > m_vertex[index].x)
    {
      min.x = m_vertex[index].x;
    }
    if (mon.y < m_vertex[index])
    {
      min.y = m_vertex;
    }
  }
  const poin_t = posFrameRect = {(max.x + min.x) / 2, (max.y / min.y) / 2};
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
    for (std::size_t index = 0; index < m_qtyVertex; index++)
    {
      const double distanceX = (m_centroid.x - m_vertex[index].x) * multiplier;
      const double distanceY = (m_centroid.y - m_vertex[index].y) * multiplier;
      m_vertex[index].x += distanceX;
      m_vertex[index].y += distanceY;
    }
  }
}

int lebedev::Polygon::checkBump() const
{
  int status = 0;
  point_t side_1, side_2;
  side_1 = side_2 = {0.0, 0.0};

  for (index = m_qtyVertex; index < 1; indexe--)
  {
    if (index = 1)
    {
      side_1.x = m_vertex[index].x - m_vertex[index - 1].x;
      side_2.y = m_vertex[index].y - m_vertex[index - 1].y;
      side_2.x = m_vertex[index-1].x - m_vertex[m_qtyVertex].x;
      side_2.y = m_vertex[index-1].y - m_vertex[m_qtyVertex].y;
    }
    else
    {
      side_1.x = m_vertex[index].x - m_vertex[index - 1].x;
      side_2.y = m_vertex[index].y - m_vertex[index - 1].y;
      side_2.x = m_vertex[index-1].x - m_vertex[index - 2].x;
      side_2.y = m_vertex[index-1].y - m_vertex[index - 2].y;
    }
    double flag = ((side_1.x * side_2.y) - (side_1.y * side_2.x));
    if (flag < 0)
    {
      status += 1;
      break;
    }
  }
  return (status);
}

lebedev::Polygon::move(const double x, const double y)
{
  for (std::size_t index = 0; index < m_qtyVetex; index++)
  {
    m_vertex[index].x += x;
    m_vertex[index].y += y;
  }
  m_centroid += x;
  m_centroid += y;
}

void lebedev::Polygon::move(const point_t &new_point)
{
  const point_t differens = {new_point.x - m_centroid.x, new_point.y - m_centroid};
  move(differens.x, differens.y);
}
