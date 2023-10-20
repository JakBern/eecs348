#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <iomanip>

#include "matrix.h"

const int kMatrixMaxSize = 100;

Matrix::Matrix(std::size_t size) {
  if (size > kMatrixMaxSize) {
    throw std::runtime_error("Matrix size > 100");
  }
  size_ = size;
  arr = new int*[size];
  for (int i = 0; i < size; i++) {
    *(arr + i) = new int[size];
  }
}

Matrix::~Matrix() {
  for (int i = 0; i < size_; i++) {
    delete[] *(arr + i);
  }
  delete[] arr;
};

std::size_t Matrix::size() const {return size_;}

void Matrix::InitFromStream(std::fstream& file_stream) {

  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {

      file_stream >> arr[i][j];

      if (file_stream.peek() == EOF && i != size_ - 1
          && j != size_ -1) {
        throw std::runtime_error(
          "End of file reached before array could be initialized.");
      }
    }
  }
};

void Matrix::Print() const {
  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {

      std::cout << std::setw(3) << arr[i][j];
      if (j == size_ - 1) {
        break;
      }
      std::cout << " ";
    }
    std::cout << "\n";
  }
  std::cout << std::flush;
};

int* Matrix::operator[](int i) const {
  return arr[i];
}

Matrix Matrix::operator+(const Matrix &other) {
  if (this->size() != other.size()) {
    throw std::runtime_error("Matrix sizes not equal during addition");
  }
  Matrix sum(this->size());
  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      sum[i][j] = (*this)[i][j] + other[i][j];
    }
  }
  return sum;
};

Matrix Matrix::operator-(const Matrix &other) {
  if (this->size() != other.size()) {
    throw std::runtime_error("Matrix sizes not equal during subtraction");
  }
  Matrix diff(this->size());
  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      diff[i][j] = (*this)[i][j] - other[i][j];
    }
  }
  return diff;
};

Matrix Matrix::Matmul(const Matrix &left, const Matrix &right) {
  std::size_t size = left.size();
  if (size != right.size()) {
    throw std::runtime_error("Matrix sizes not equal during multiplication");
  }
  Matrix product(size);
  for (std::size_t col = 0; col < size; col++) {
    for (std::size_t row = 0; row < size; row++) {
      int sum = 0;
      for (int i = 0; i < size; i++) {
        sum += left[row][i] * right[i][col];
      }
      product[row][col] = sum;
    }
  }
  return product;
}