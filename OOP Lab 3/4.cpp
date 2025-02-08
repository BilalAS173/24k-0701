#include <iostream>
#include <cstdlib>
using namespace std;

class employee {
public:
    string firstname;
    string lastname;
    double monthlysalary;

    void testsalary(double &monthlysalary) {
        if (monthlysalary < 0) {
            monthlysalary = 0.0;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 7) { 
        cout << "Usage: " << argv[0] << " <firstname1> <lastname1> <salary1> <firstname2> <lastname2> <salary2>\n";
        return 1;
    }

    employee e[2];

    for (int i = 0; i < 2; i++) {
        e[i].firstname = argv[1 + i * 3];
        e[i].lastname = argv[2 + i * 3];
        e[i].monthlysalary = stod(argv[3 + i * 3]); 
        e[i].testsalary(e[i].monthlysalary);
    }

    for (int i = 0; i < 2; i++) {
        e[i].monthlysalary *= 1.1; 
        cout << e[i].firstname << " " << e[i].lastname 
             << " yearly salary after raise is: " << e[i].monthlysalary * 12 << endl;
    }

    return 0;
}
