#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>
#include <algorithm>

namespace gusarov
{
  template <typename T>
  class Matrix
  {
  public:
    using ptr = std::shared_ptr<T>;
    using arr = std::unique_ptr<ptr []>;

    class Layer
    {
    public:
      Layer(const Layer &);
      Layer(Layer &&);
      Layer(ptr *, size_t);
      ~Layer() = default;

      Layer &operator =(const Layer &);
      Layer &operator =(Layer &&);
      ptr operator [](size_t) const;

      size_t size() const;
      void swap(Layer &);
    private:
      size_t size_;
      arr array_;
    };

    Matrix();
    Matrix(const Matrix<T> &);
    Matrix(Matrix<T> &&);
    ~Matrix() = default;
    Matrix &operator =(const Matrix<T> &);
    Matrix &operator =(Matrix<T> &&);
    Layer operator [](size_t) const;
    bool operator ==(const Matrix<T> &) const;
    bool operator !=(const Matrix<T> &) const;
    void add(ptr, size_t);
    size_t getRows() const;
    size_t getSize() const;
    void swap(Matrix<T> &);
  private:
    size_t rows_;
    size_t size_;
    std::unique_ptr<size_t []> cols_;
    std::unique_ptr<std::shared_ptr<T> []> data_;
  };

  template<typename T>
  gusarov::Matrix<T>::Matrix() :
    rows_(0),
    size_(0)
  {
  }

  template<typename T>
  gusarov::Matrix<T>::Matrix(const gusarov::Matrix<T> &newMatrix):
    rows_(newMatrix.rows_),
    size_(newMatrix.size_),
    cols_(std::make_unique<size_t []>(newMatrix.rows_)),
    data_(std::make_unique<ptr []>(newMatrix.size_))
  {
    for (size_t i = 0; i < rows_; ++i)
    {
      cols_[i] = newMatrix.cols_[i];
    }
    for (size_t i = 0; i < size_; ++i)
    {
      data_[i] = newMatrix.data_[i];
    }
  }

  template<typename T>
  gusarov::Matrix<T>::Matrix(gusarov::Matrix<T> &&newMatrix):
    rows_(newMatrix.rows_),
    size_(newMatrix.size_),
    cols_(std::move(newMatrix.cols_)),
    data_(std::move(newMatrix.data_))
  {
    newMatrix.rows_ = 0;
    newMatrix.size_ = 0;
  }

  template<typename T>
  gusarov::Matrix<T> &gusarov::Matrix<T>::operator =(const gusarov::Matrix<T> &newMatrix)
  {
    if (this != &newMatrix)
    {
        rows_ = newMatrix.rows_;
        size_ = newMatrix.columns_;
        cols_ = std::move(newMatrix.cols_);
        data_ = std::move(newMatrix.data_);
        newMatrix.rows_ = 0;
        newMatrix.columns_ = 0;

    }

    return *this;
  }

  template<typename T>
  gusarov::Matrix<T> &gusarov::Matrix<T>::operator =(gusarov::Matrix<T> &&newMatrix)
  {
    if (this != &newMatrix)
    {
        Matrix<T>(newMatrix).swap(*this);

    }

    return *this;
  }

  template<typename T>
  typename Matrix<T>::Layer gusarov::Matrix<T>::operator [](size_t row) const
  {
    if (row >= rows_)
    {
      throw std::out_of_range("Index is out of range");
    }

    size_t index = 0;
    for (size_t i = 0; i < row; ++i)
    {
      index += cols_[i];
    }

    return gusarov::Matrix<T>::Layer(&data_[index], cols_[row]);
  }

  template<typename T>
  bool gusarov::Matrix<T>::operator ==(const gusarov::Matrix<T>& matrix) const
  {
    if ((rows_ != matrix.rows_) || (size_ != matrix.size_))
    {
      return false;
    }

    for (size_t i = 0; i < rows_; ++i)
    {
      if (cols_[i] != matrix.cols_[i])
      {
        return false;
      }
    }

    for (size_t i = 0; i < size_; ++i)
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
  void gusarov::Matrix<T>::add(ptr newShape, size_t rows)
  {
    if (rows > rows_)
    {
      throw std::out_of_range("Index is out of range");
    }

    if (!newShape)
    {
      throw std::invalid_argument("Pointer must be differ nullptr");
    }

    arr newData = std::make_unique<ptr []>(size_ + 1);
    size_t index1 = 0;
    size_t index2 = 0;
    for (size_t i = 0; i < rows_; ++i)
    {
      for (size_t j = 0; j < cols_[i]; ++j)
      {
        newData[index1++] = data_[index2++];
      }
      if (rows == i)
      {
        newData[index1++] = newShape;
        ++cols_[rows];
      }
    }

    if (rows == rows_)
    {
      std::unique_ptr<size_t []> newColumns = std::make_unique<size_t []>(rows_ + 1);
      for (size_t i = 0; i < rows_; ++i)
      {
        newColumns[i] = cols_[i];
      }
      newColumns[rows] = 1;
      newData[size_] = newShape;
      rows_++;
      cols_.swap(newColumns);
    }
    data_.swap(newData);
    size_++;
}

  template<typename T>
  size_t gusarov::Matrix<T>::getRows() const
  {
    return rows_;
  }

  template<typename T>
  size_t gusarov::Matrix<T>::getSize() const
  {
    return size_;
  }

  template <typename T>
  void Matrix<T>::swap(Matrix<T> &swapMatrix)
  {
    std::swap(rows_, swapMatrix.rows_);
    std::swap(size_, swapMatrix.size_);
    std::swap(cols_, swapMatrix.cols_);
    std::swap(data_, swapMatrix.data_);
  }

  template <typename T>
  Matrix<T>::Layer::Layer(const Matrix<T>::Layer &newArray):
    size_(newArray.size_),
    array_(std::make_unique<ptr []>(newArray.size_))
  {
    for (int i = 0; i < size_; i++)
    {
      array_[i] = newArray.array_[i];
    }
  }

  template <typename T>
  Matrix<T>::Layer::Layer(Matrix<T>::Layer &&newArray):
    size_(newArray.size_),
    array_(std::move(newArray.array_))
  {
    newArray.size_ = 0;
  }

  template <typename T>
  Matrix<T>::Layer::Layer(ptr *newArray, size_t size):
    size_(size),
    array_(std::make_unique<ptr []>(size))
  {
    for (size_t i = 0; i < size_; i++)
    {
      array_[i] = newArray[i];
    }
  }

  template <typename T>
  typename Matrix<T>::Layer &Matrix<T>::Layer::operator =(const Matrix<T>::Layer &newArray)
  {
    if (this != &newArray)
    {
      Matrix<T>::Layer(newArray).swap(*this);
    }

    return *this;
  }

  template <typename T>
  typename Matrix<T>::Layer &Matrix<T>::Layer::operator =(Matrix<T>::Layer &&newArray)
  {
    if (this != &newArray)
    {
      size_ = newArray.size_;
      newArray.size_ = 0;
      array_ = std::move(newArray.array_);
    }
  }

  template <typename T>
  typename Matrix<T>::ptr Matrix<T>::Layer::operator [](size_t index) const
  {
    if (index >= size_)
    {
      throw std::out_of_range("Index less than size");
    }
    return array_[index];
  }

  template <typename T>
  size_t Matrix<T>::Layer::size() const
  {
    return size_;
  }

  template <typename T>
  void Matrix<T>::Layer::swap(Layer &swapArray)
  {
    std::swap(size_, swapArray.size_);
    std::swap(array_, swapArray.array_);
  }

}
#endif
