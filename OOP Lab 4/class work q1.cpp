#include <iostream>
using namespace std;

class matrix {
private:
    int rows;
    int columns;
    double** value;  

public:
    matrix() : rows(0), columns(0), value(nullptr) {}

    matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        value = new double*[rows];  
        for (int i = 0; i < rows; i++) {
            value[i] = new double[columns](); 
        }
    }

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

    matrix(matrix&& other) noexcept {
        rows = other.rows;
        columns = other.columns;
        value = other.value; 
        other.value = nullptr;  
        other.rows = 0;
        other.columns = 0;
    }

    ~matrix() {
        if (value) {
            for (int i = 0; i < rows; i++) {
                delete[] value[i];
            }
            delete[] value;
        }
    }

    int getrows() const {
        return rows;
    }
    int getcolumns() const {
        return columns;
    }

    double& at(int r, int c) {
        return value[r][c];  
    }

    void fill(double fillValue) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                value[i][j] = fillValue;
            }
        }
    }

    matrix transpose() {
        matrix transposed(columns, rows);  
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                transposed.value[j][i] = value[i][j];  
            }
        }
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

int main() {
    int x, y;
    cout << "Enter the number of rows: ";
    cin >> x;
    cout << "Enter the number of columns: ";
    cin >> y;

    matrix obj1(x, y);
    obj1.fill(5.00);

    matrix obj2(obj1);

    matrix obj3(move(obj2));

    matrix transposed = obj1.transpose();

    return 0;
}
