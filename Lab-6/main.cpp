#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>

const int kMatrixMaxSize = 100;

void InitFromStream(std::vector<std::vector<int>>&, 
                    std::fstream&,
                    std::size_t);

void PrintMatrix(std::vector<std::vector<int>>);

std::vector<std::vector<int>> MatAdd(
                                const std::vector<std::vector<int>>&, 
                                const std::vector<std::vector<int>>&);

std::vector<std::vector<int>> MatDiff(
                                const std::vector<std::vector<int>>&, 
                                const std::vector<std::vector<int>>&);

std::vector<std::vector<int>> MatMul(
                                const std::vector<std::vector<int>>&, 
                                const std::vector<std::vector<int>>&);


int main() {
  std::cout << "Jake Bernard\nLab #6: Matrix Multiplication\n";
  std::fstream file;
  while (true) {
    std::cout << "Enter filename: \n";
    std::string filename;
    std::cin >> filename;
    file.open(filename);
    if (file.is_open()) {
      break;
    }
    else {
      std::cout << "File not found. Please try again.\n";
    }
  }

  std::size_t size;
  file >> size;
  std::vector<std::vector<int>> a(size, std::vector<int> (size, 0));
  std::vector<std::vector<int>> b(size, std::vector<int> (size, 0));
  InitFromStream(a, file, size);
  InitFromStream(b, file, size);
  std::cout << "\nMatrix A:\n";
  PrintMatrix(a);
  std::cout << "\nMatrix B:\n";
  PrintMatrix(b);
  std::cout << "\nMatrix Sum (A + B):\n";
  PrintMatrix(MatAdd(a, b));
  std::cout << "\nMatrix Product (A * B):\n";
  PrintMatrix(MatMul(a, b));
  std::cout << "\nMatrix Difference (A - B):\n";
  PrintMatrix(MatDiff(a, b));

  return 0;
}

void InitFromStream(std::vector<std::vector<int>> &a, 
                    std::fstream& file_stream,
                    std::size_t size) {

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      file_stream >> a[i][j];

      if (file_stream.peek() == EOF && i != size - 1
          && j != size -1) {
        throw std::runtime_error(
          "End of file reached before array could be initialized.");
      }
    }
  }
};

void PrintMatrix(std::vector<std::vector<int>> arr) {
  std::size_t size = arr.size();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {

      std::cout << std::setw(3) << arr[i][j];
      if (j == size - 1) {
        break;
      }
      std::cout << " ";
    }
    std::cout << "\n";
  }
  std::cout << std::flush;
};

std::vector<std::vector<int>> MatAdd(
                                const std::vector<std::vector<int>> &first, 
                                const std::vector<std::vector<int>> &second) {
  if (first.size() != second.size()) {
    throw std::runtime_error("Matrix sizes not equal during addition");
  }
  std::size_t size = first.size();
  std::vector<std::vector<int>> sum(first.size(), 
                                std::vector<int>(first.size(), 0));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      sum[i][j] = first[i][j] + second[i][j];
    }
  }
  return sum;
};

std::vector<std::vector<int>> MatDiff(
                                const std::vector<std::vector<int>> &first, 
                                const std::vector<std::vector<int>> &second) {
  if (first.size() != second.size()) {
    throw std::runtime_error("Matrix sizes not equal during addition");
  }
  std::size_t size = first.size();
  std::vector<std::vector<int>> diff(first.size(), 
                                std::vector<int>(first.size(), 0));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      diff[i][j] = first[i][j] - second[i][j];
    }
  }
  return diff;
};

std::vector<std::vector<int>> MatMul(
                                const std::vector<std::vector<int>> &left, 
                                const std::vector<std::vector<int>> &right) {
  std::size_t size = left.size();
  if (size != right.size()) {
    throw std::runtime_error("Matrix sizes not equal during multiplication");
  }
  std::vector<std::vector<int>> product(size, 
                                std::vector<int>(size, 0));
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