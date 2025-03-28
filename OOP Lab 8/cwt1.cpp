#include<iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int x, int y) : numerator(x), denominator(y) {
        reducefraction();  // Reduce fraction on construction
    }
    
    Fraction() : numerator(0), denominator(1) {}  // Default constructor
    
    int gcd() {
        int a = numerator;
        int b = denominator;
        while (b != 0) {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    
    void reducefraction() {
        int divisor = gcd();
        numerator /= divisor;
        denominator /= divisor;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    
    void display() {
        cout << "Fraction: " << numerator << "/" << denominator << endl;
    }
    
    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "Error: Cannot divide by zero" << endl;
            return Fraction(0, 1);
        } else {
            return Fraction(numerator * other.denominator, denominator * other.numerator);
        }
    }

    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator;
        if (f.denominator != 1) os << '/' << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        int num, denom = 1;
        char slash;
        is >> num;
        if (is.peek() == '/') {
            is >> slash >> denom;
        }
        f = Fraction(num, denom);
        return is;
    }
};

int main() {
    Fraction a(1, 2);
    Fraction b(3, 4);
    Fraction zero(0, 1);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a / zero = " << a / zero << endl;  // Will show error message

    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;

    return 0;
}