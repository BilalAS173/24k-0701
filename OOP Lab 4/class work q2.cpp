#include <iostream>
using namespace std;

class polynomial {
public:
    double* coefficients;  // Dynamically allocated array
    int highestpower;  // Degree of polynomial

    // ✅ Default Constructor
    polynomial() {
        highestpower = 0;
        coefficients = new double[1];
        coefficients[0] = 0;  // Initialize with zero
    }

    // ✅ Parameterized Constructor (Deep Copy)
    polynomial(int degree, double* array) {
        highestpower = degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = array[i];  // Deep copy
        }
    }

    // ✅ Copy Constructor (Deep Copy)
    polynomial(const polynomial& other) {
        highestpower = other.highestpower;
        coefficients = new double[highestpower + 1];
        for (int i = 0; i <= highestpower; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }

    // ✅ Move Constructor (Efficient Transfer of Ownership)
    polynomial(polynomial&& other) noexcept {
        highestpower = other.highestpower;
        coefficients = other.coefficients;
        other.coefficients = nullptr;
        other.highestpower = 0;
    }

    // ✅ Destructor
    ~polynomial() {
        delete[] coefficients;
    }

    // ✅ Get Degree
    int getDegree() const {
        return highestpower;
    }

    // ✅ Evaluate Polynomial at x
    double evaluate(double x) const {
        double result = 0;
        double power = 1;  // x^0 = 1
        for (int i = 0; i <= highestpower; i++) {
            result += coefficients[i] * power;
            power *= x;  // Compute x^i iteratively
        }
        return result;
    }

    // ✅ Add Two Polynomials
    polynomial add(const polynomial& other) const {
        int maxDegree = max(highestpower, other.highestpower);
        double* newCoefficients = new double[maxDegree + 1]();

        for (int i = 0; i <= highestpower; i++) {
            newCoefficients[i] += coefficients[i];
        }
        for (int i = 0; i <= other.highestpower; i++) {
            newCoefficients[i] += other.coefficients[i];
        }

        return polynomial(maxDegree, newCoefficients);
    }

    // ✅ Multiply Two Polynomials
    polynomial multiply(const polynomial& other) const {
        int newDegree = highestpower + other.highestpower;
        double* newCoefficients = new double[newDegree + 1]();

        for (int i = 0; i <= highestpower; i++) {
            for (int j = 0; j <= other.highestpower; j++) {
                newCoefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return polynomial(newDegree, newCoefficients);
    }
};

int main() {
    double coeffs1[] = {1, 2, 6};  // Represents 1 + 2x + 3x^2
    polynomial p1(2, coeffs1);

    double coeffs2[] = {3, 4};  // Represents 4 + 5x
    polynomial p2(1, coeffs2);

    polynomial sum = p1.add(p2);
    polynomial product = p1.multiply(p2);

    cout << "Sum Degree is: " << sum.getDegree() << endl;
    cout << "Product Degree is: " << product.getDegree() << endl;

    return 0;
}
