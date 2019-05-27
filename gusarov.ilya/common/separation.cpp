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

gusarov::Matrix<gusarov::Shape> gusarov::section(const gusarov::CompositeShape &compShape)
{
  gusarov::Matrix<gusarov::Shape> matrix;

  for (size_t i = 0; i < compShape.getSize(); ++i)
  {
    size_t layerCount = 0;
    size_t layerIndex = 0;

    for (size_t j = 0; j < matrix.getRows(); ++j) {
      for (size_t k = 0; k < matrix.getColumns(); ++k) {
        if (matrix[j][k] == nullptr) {
          layerCount = j;
          layerIndex = k;
          break;
        }
        if (intersect(compShape[i]->getFrameRect(), matrix[j][k]->getFrameRect())) {
          layerCount = j + 1;
          layerIndex = 0;
          break;
        }
        if (k == matrix.getColumns() - 1) {
          layerIndex = k + 1;
        }
      }
    }
    matrix.add(compShape[i], layerCount, layerIndex);
  }

  return matrix;
}
