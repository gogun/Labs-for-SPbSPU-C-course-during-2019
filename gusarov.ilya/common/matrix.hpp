#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>

namespace gusarov
{
  template <typename T>
  class Matrix
  {
  public:
    using ptr = std::shared_ptr<T>;
    using arr = std::unique_ptr<ptr []>;

    Matrix();
    Matrix(const Matrix<T> &);
    Matrix(Matrix<T> &&);
    ~Matrix() = default;
    Matrix &operator =(const Matrix<T> &);
    Matrix &operator =(Matrix<T> &&);
    arr operator [](size_t) const;
    bool operator ==(const Matrix<T> &) const;
    bool operator !=(const Matrix<T> &) const;
    void add(ptr, size_t, size_t);
    size_t getRows() const;
    size_t getColumns() const;
  private:
    size_t rows_;
    size_t columns_;
    arr data_;
  };

  template<typename T>
  gusarov::Matrix<T>::Matrix() :
    rows_(0),
    columns_(0),
    data_(nullptr)
  {
  }

  template<typename T>
  gusarov::Matrix<T>::Matrix(const gusarov::Matrix<T> &newMatrix):
    rows_(newMatrix.rows_),
    columns_(newMatrix.columns_),
    data_(std::make_unique<ptr []>(newMatrix.rows_ * newMatrix.columns_))
  {
    for (size_t i = 0; i < rows_ * columns_; ++i)
    {
      data_[i] = newMatrix.data_[i];
    }
  }

  template<typename T>
  gusarov::Matrix<T>::Matrix(gusarov::Matrix<T> &&newMatrix):
    rows_(newMatrix.rows_),
    columns_(newMatrix.columns_),
    data_(std::move(newMatrix.data_))
  {
    newMatrix.rows_ = 0;
    newMatrix.columns_ = 0;
  }

  template<typename T>
  gusarov::Matrix<T> &gusarov::Matrix<T>::operator =(const gusarov::Matrix<T> &newMatrix)
  {
    if (this != &newMatrix)
    {
      data_ = std::make_unique<ptr[]>(newMatrix.rows_ * newMatrix.cols_);
      for (size_t i = 0; i < newMatrix.rows_ * newMatrix.cols_; ++i)
      {
        data_[i] = newMatrix.data_[i];
      }
      rows_ = newMatrix.rows_;
      columns_ = newMatrix.cols_;
    }

    return *this;
  }

  template<typename T>
  gusarov::Matrix<T> &gusarov::Matrix<T>::operator =(gusarov::Matrix<T> &&newMatrix)
  {
    if (this != &newMatrix)
    {
      rows_ = newMatrix.rows_;
      newMatrix.rows_ = 0;
      columns_ = newMatrix.columns_;
      newMatrix.columns_ = 0;
      data_ = std::move(newMatrix.data_);
    }

    return *this;
  }

  template<typename T>
  std::unique_ptr<std::shared_ptr<T>[]> gusarov::Matrix<T>::operator [](size_t row) const
  {
    if (row >= rows_)
    {
      throw std::out_of_range("Index is out of range");
    }

    arr tmpArray = std::make_unique<ptr []>(columns_);
    for (size_t i = 0; i < columns_; ++i)
    {
      tmpArray[i] = data_[i + row * columns_];
    }
    
    return tmpArray;
  }

  template<typename T>
  bool gusarov::Matrix<T>::operator ==(const gusarov::Matrix<T>& matrix) const
  {
    if ((rows_ != matrix.rows_) || (columns_ != matrix.columns_))
    {
      return false;
    }

    for (size_t i = 0; i < (rows_ * columns_); ++i)
    {
      if (data_[i] != matrix.data_[i])
      {
        return false;
      }
    }

    return true;
  }

  template<typename T>
  bool gusarov::Matrix<T>::operator !=(const gusarov::Matrix<T> &matrix) const
  {
    return !(*this == matrix);
  }

  template<typename T>
  void gusarov::Matrix<T>::add(ptr newShape, size_t rows, size_t columns)
  {
    if ((rows >= rows_) || (columns >= columns_))
    {
      const size_t rowsTmp = std::max(rows + 1, rows_);
      const size_t columnsTmp = std::max(columns + 1, columns_);
      arr tmpArr = std::make_unique<ptr []>(rowsTmp * columnsTmp);

      for (size_t i = 0; i < rows_; ++i)
      {
        for (size_t j = 0; j < columns_; ++j)
        {
          tmpArr[i * columnsTmp + j] = data_[i * columns_ + j];
        }
      }

      data_ = std::move(tmpArr);
      rows_ = rowsTmp;
      columns_ = columnsTmp;
    }

    data_[rows * columns_ + columns] = newShape;
  }

  template<typename T>
  size_t gusarov::Matrix<T>::getRows() const
  {
    return rows_;
  }

  template<typename T>
  size_t gusarov::Matrix<T>::getColumns() const
  {
    return columns_;
  }

}
#endif
