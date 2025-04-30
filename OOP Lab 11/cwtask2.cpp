#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

class DimensionMismatchException : public runtime_error {
public:
    DimensionMismatchException(const string& what) : runtime_error(what) {}
};

class OutOfBoundsException : public runtime_error {
public:
    OutOfBoundsException(const string& what) : runtime_error(what) {}
};

template<typename T>
class Matrix {
private:
    size_t rows;
    size_t cols;
    vector<vector<T>> data;

    void validateDimensions(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException("Matrix dimensions do not match");
        }
    }

    void validateMultiplicationDimensions(const Matrix& other) const {
        if (cols != other.rows) {
            throw DimensionMismatchException(
                "Number of columns in first matrix must match number of rows in second matrix");
        }
    }

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, vector<T>(cols)) {}

    Matrix(size_t rows, size_t cols, const T& initValue) : 
        rows(rows), cols(cols), data(rows, vector<T>(cols, initValue)) {}

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    T& at(size_t row, size_t col) {
        if (row >= rows || col >= cols) {
            throw OutOfBoundsException("Matrix indices out of bounds");
        }
        return data[row][col];
    }

    const T& at(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw OutOfBoundsException("Matrix indices out of bounds");
        }
        return data[row][col];
    }

    Matrix operator+(const Matrix& other) const {
        validateDimensions(other);
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        validateMultiplicationDimensions(other);
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    // Create and initialize two matrices
    Matrix<int> A(2, 3);
    A.at(0, 0) = 1; A.at(0, 1) = 2; A.at(0, 2) = 3;
    A.at(1, 0) = 4; A.at(1, 1) = 5; A.at(1, 2) = 6;

    Matrix<int> B(3, 2);
    B.at(0, 0) = 7; B.at(0, 1) = 8;
    B.at(1, 0) = 9; B.at(1, 1) = 10;
    B.at(2, 0) = 11; B.at(2, 1) = 12;

    // Print the matrices
    cout << "Matrix A (2x3):\n";
    A.print();
    cout << "\nMatrix B (3x2):\n";
    B.print();

    // Demonstrate multiplication
    cout << "\nMatrix Multiplication (A * B):\n";
    Matrix<int> C = A * B;
    C.print();

    // Create another matrix for addition demo
    Matrix<int> D(2, 3);
    D.at(0, 0) = 6; D.at(0, 1) = 5; D.at(0, 2) = 4;
    D.at(1, 0) = 3; D.at(1, 1) = 2; D.at(1, 2) = 1;

    cout << "\nMatrix D (2x3):\n";
    D.print();

    // Demonstrate addition
    cout << "\nMatrix Addition (A + D):\n";
    Matrix<int> E = A + D;
    E.print();

    // Demonstrate error handling
    cout << "\nDemonstrating error handling:\n";
    try {
        cout << "Attempting invalid addition (A + B):\n";
        Matrix<int> F = A + B; // This will throw
    } catch (const DimensionMismatchException& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "\nAttempting invalid matrix access:\n";
        A.at(10, 10) = 99; // This will throw
    } catch (const OutOfBoundsException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}