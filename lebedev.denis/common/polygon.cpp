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
  lebedev::poin_t temp_point = {0.0, 0.0};
  for (std::size_t index = 0; index < m_qtyVetex; index++)
  {
    temp_point.x += m_vertex[index].x;
    temp_point.y += m_vertex[index].y;
  }
  m_centroid = {temp_point.x / m_qtyVetex, temp_point.y / m_qtyVetex};
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

l
