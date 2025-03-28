#include<iostream>
#include<vector>
using namespace std;

class polynomialutlis;
class polynomial {
    protected:
    vector<int> coefficient;
    public:
    polynomial () {
   //empty polynomial;
    }
    public:
friend polynomialutlis;
polynomial operator+(const polynomial&other) const {

}
polynomial operator-(const polynomial&other) const {

}
polynomial operator*(const polynomial&other) const {

}

friend ostream& operator<<(ostream& os, const polynomial& f) {
    os << 
    
    return os;
}
};
class polynomialutlis {
public:
int evaluate (const polynomial &x, int y) {

}
void polynomialderivative (const polynomial &p) {

}
};
int main () {
    
}