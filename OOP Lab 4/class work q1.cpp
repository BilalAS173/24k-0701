#include <iostream>
using namespace std;

class matrix {
private:
    int rows;
    int columns;
    double** value;  // Use double instead of int

public:
    // Default constructor
    matrix() : rows(0), columns(0), value(nullptr) {}

    // Parameterized constructor
    matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        value = new double*[rows];  
        for (int i = 0; i < rows; i++) {
            value[i] = new double[columns]();  // Initialize to 0
        }
    }

    // Copy constructor (Deep Copy)
    matrix(const matrix& other) {
        rows = other.rows;
        columns = other.columns;
        value = new double*[rows];
        for (int i = 0; i < rows; i++) {
            value[i] = new double[columns];
            for (int j = 0; j < columns; j++) {
                value[i][j] = other.value[i][j];  
            }
        }
    }

    // Move constructor
    matrix(matrix&& other) noexcept {
        rows = other.rows;
        columns = other.columns;
        value = other.value; 
        other.value = nullptr;  // Avoid double deletion
        other.rows = 0;
        other.columns = 0;
    }

    // Destructor
    ~matrix() {
        if (value) {
            for (int i = 0; i < rows; i++) {
                delete[] value[i];
            }
            delete[] value;
        }
    }

    // Getters
    int getrows() const {
        return rows;
    }
    int getcolumns() const {
        return columns;
    }

    // Access element
    double& at(int r, int c) {
        return value[r][c];  
    }

    // Fill the matrix
    void fill(double fillValue) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                value[i][j] = fillValue;
            }
        }
    }

    // Transpose function
    matrix transpose() {
        matrix transposed(columns, rows);  
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                transposed.value[j][i] = value[i][j];  
            }
        }

        // Printing the transposed matrix
        cout << "Transposed Matrix: " << endl;
        for (int i = 0; i < transposed.rows; i++) {
            for (int j = 0; j < transposed.columns; j++) {
                cout << transposed.value[i][j] << " ";
            }
            cout << endl;
        }

        return transposed;  
    }
};

// Main function
int main() {
    int x, y;
    cout << "Enter the number of rows: ";
    cin >> x;
    cout << "Enter the number of columns: ";
    cin >> y;

    // Creating a matrix object
    matrix obj1(x, y);
    obj1.fill(4.00);

    // Copy constructor
    matrix obj2(obj1);

    // Move constructor
    matrix obj3(move(obj2));

    // Transpose
    matrix transposed = obj1.transpose();

    return 0;
}
