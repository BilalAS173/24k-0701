#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;  
    int cols;   
    int **mat;  

public:
    Matrix(int r, int c) : rows(r), cols(c) {
    
        mat = new int*[rows];
     
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                mat[i][j] = 0;  
            }
        }
    }
    
    // Copy constructor (deep copy)
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }
    
    // Copy assignment operator (deep copy)
    Matrix& operator=(const Matrix &other) {
        if (this != &other) { 
            for (int i = 0; i < rows; i++) {
                delete [] mat[i];
            }
            delete [] mat;
            
            rows = other.rows;
            cols = other.cols;
            mat = new int*[rows];
            for (int i = 0; i < rows; i++) {
                mat[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        }
        return *this;
    }
    
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete [] mat[i];
        }
        delete [] mat;
    }
    
    int getRows() const {
        return rows;
    }
    
    int getCols() const {
        return cols;
    }
    
    void setElement(int i, int j, int value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            cout << "Index (" << i << "," << j << ") is out of range." << endl;
            return;
        }
        mat[i][j] = value;
    }
    
    int getElement(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            cout << "Index (" << i << "," << j << ") is out of range." << endl;
            return 0;
        }
        return mat[i][j];
    }
    
    Matrix add(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices cannot be added due to mismatched dimensions." << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }
    
    Matrix multiply(const Matrix &other) const {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied due to mismatched dimensions." << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += this->mat[i][k] * other.mat[k][j];
                }
                result.mat[i][j] = sum;
            }
        }
        return result;
    }
    
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
 
    Matrix m1(2, 3);
    Matrix m2(2, 3);
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            m1.setElement(i, j, i + 3); 
            m2.setElement(i, j, j + 4);  
        }
    }
    
    cout << "Matrix m1:" << endl;
    m1.print();
    cout << "\nMatrix m2:" << endl;
    m2.print();
    
    Matrix addResult = m1.add(m2);
    cout << "\nAddition Result (m1 + m2):" << endl;
    addResult.print();
    
    Matrix m3(3, 2);  
    m3.setElement(0, 0, 1);
    m3.setElement(0, 1, 2);
    m3.setElement(1, 0, 3);
    m3.setElement(1, 1, 4);
    m3.setElement(2, 0, 5);
    m3.setElement(2, 1, 6);
    
    cout << "\nMatrix m3:" << endl;
    m3.print();
    
    Matrix multResult = m1.multiply(m3);
    cout << "\nMultiplication Result (m1 x m3):" << endl;
    multResult.print();
    
    return 0;
}
