#include "separation.hpp"
#include <cmath>

bool gusarov::intersect(const rectangle_t &frameRect1, const rectangle_t &frameRect2)
{
  if ((fabs(frameRect1.pos.x - frameRect2.pos.x)) > ((frameRect1.width + frameRect2.width) / 2))
  {
    return false;
  }
  if ((fabs(frameRect1.pos.y - frameRect2.pos.y)) > ((frameRect1.height + frameRect2.height) / 2))
  {
    return false;
  }

  return true;
}

gusarov::Matrix<gusarov::Shape> gusarov::section(const gusarov::CompositeShape comShape)
{
  gusarov::Matrix<gusarov::Shape> matrix;

  size_t count = comShape.getSize();
  for (size_t i = 0; i < count; i++)
  {
    size_t layer = 0;
    size_t matrixRows = matrix.getRows();
    for (size_t j = matrixRows; j-- > 0;)
    {
      size_t matrixColumns = matrix[j].size();
      for (size_t k = 0; k < matrixColumns; k++)
      {
        if (intersect(matrix[j][k]->getFrameRect(), comShape[i]->getFrameRect()))
        {
          layer = j + 1;
          break;
        }
      }

      if (layer > j)
      {
        break;
      }
    }

    matrix.add(comShape[i], layer);
  }

  return matrix;
}

