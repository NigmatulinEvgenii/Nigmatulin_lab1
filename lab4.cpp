#include <iostream>
using namespace std;

int getInt();
long long int doubleFact(int number);

int main() {
    int n;
    cout << "Input n to find n!!: ";
    n = getInt();
    cout << "n!! = " << doubleFact(n) << endl;
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

long long int doubleFact(int number)
{

    if (number < 3)
        return number;
    else
        return number * doubleFact(number - 2);
}