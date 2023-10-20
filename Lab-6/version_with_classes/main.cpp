#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "matrix.h"

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
  Matrix a(size);
  Matrix b(size);
  a.InitFromStream(file);
  b.InitFromStream(file);
  std::cout << "\nMatrix A:\n";
  a.Print();
  std::cout << "\nMatrix B:\n";
  b.Print();
  std::cout << "\nMatrix Sum (A + B):\n";
  (a + b).Print();
  std::cout << "\nMatrix Product (A * B):\n";
  (Matrix::Matmul(a, b)).Print();
  std::cout << "\nMatrix Difference (A - B):\n";
  (a - b).Print();

  return 0;
}