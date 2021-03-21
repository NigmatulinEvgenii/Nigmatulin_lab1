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
            else
            {
                cout << "n cannot be less 0. \n";
            }
        }
        else
        {
            cin.ignore(32767, '\n');
            return n;
        }
    }
}

double getFactorial(double n)
{
    double factorial = 1;

    if (n == 0)
    {
        return 1;
    }
    else
    {
        do
        {
            factorial *= n;
            n -= 2;
        } while (n > 1);

        return factorial;
    }
}

int main()
{
    double n = getValue();

    cout << "The double factorial of n is: " << getFactorial(n);

    return 0;
}