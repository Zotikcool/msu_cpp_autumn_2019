#include <iostream>
#include <cctype>
#include <string.h>
#include "matrix.h"

int main(int argc, char **argv) {
    const size_t rows = 5;
    const size_t cols = 3;
    Matrix f1(rows, cols);
    Matrix f2(rows, cols);
    if (f1.getRows() != rows || f1.getColumns() != cols) {
        std::cout << "Wrong size of matrix." << std::endl;
    }

    f1[3][1] = 3;
    if (f1[3][1] != 3) {
        std::cout << "Wrong value of element." << std::endl;
    }

    f1 *= 2;
    if (f1[3][1] != 6) {
        std::cout << "Wrong value of element after multiplying." << std::endl;
    }

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            f1[i][j] = 2;
            f2[i][j] = 2;
        }
    }
    if (!(f1 == f2)) {
        std::cout << "Incorrect comparison of two matrices." << std::endl;
    }

    f2[1][1] = 5;
    if (!(f1 != f2)) {
        std::cout << "Incorrect comparison of two matrices." << std::endl;
    }
    std::cout << "Done." << std::endl;
    return 0;
}
