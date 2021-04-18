#include <iostream>
using namespace std;

int getInt();

class doubleFact {
public:
    long long int calculate();
    void setN();
private:
    int n;
    long long int doubleFactorial(int number);
};

long long int doubleFact::calculate() {
    return doubleFactorial(n);
}

void doubleFact::setN() {
    cout << "Input n to find n!!: ";
    while (true) {
        n = getInt();
        if (n < 0)
            cout << "n must be > 0, do input again: ";
        else
            break;
    }
}

long long int doubleFact::doubleFactorial(int number) {
    if (number < 3)
        return number;
    else
        return number * doubleFactorial(number - 2);
}

int main() {
    doubleFact df;
    df.setN();
    cout << "n!! = " << df.calculate() << endl;
    return 0;
}

int getInt() {
    while (true) {
        int number;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Do input again." << endl;
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}