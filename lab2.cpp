#include <iostream>

using namespace std;

double getValue()
{
    while (true)
    {
        cout << "Enter the number n: ";
        double n;
        cin >> n;
        if ((cin.fail()) || (n < 0))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "n - number. \n";
            }
            else cout << "n cannot be less 0. \n";
        }
        else
        {
            cin.ignore(32767, '\n');
            return n;
        }
    }
}

int main()
{
    double factorial = 1;
    double n = getValue();
    if (n == 0) 
    {
        cout << "The factorial of n is: 1";
        return 0;
    }
    do {
        factorial *= n;
        n -= 2;
    } while (n > 1);
    cout << "The factorial of n is: " << factorial;
    return 0;
}