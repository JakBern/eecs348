#ifndef LAB6_MATRIX_H_
#define LAB6_MATRIX_H_

#include <cstdlib>
#include <fstream>

class Matrix {
  private:
    std::size_t size_;
    int **arr;

  public:

  Matrix(std::size_t size);
  ~Matrix();


  std::size_t size() const;

  void InitFromStream(std::fstream& file_stream);

  void Print() const;

  int* operator[](int i) const;
  Matrix operator+(const Matrix &other);
  Matrix operator-(const Matrix &other);

  static Matrix Matmul(const Matrix &left, const Matrix &right);

};

#endif