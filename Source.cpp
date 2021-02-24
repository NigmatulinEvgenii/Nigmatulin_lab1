/*
Author: Nigmatulin Evgenii
Group: СБС-002-О-01 / 2
Task: 1.8
Description: вычислить пройденный поездом, если он едет на протяжении временис постоянной скоростью, а затем такой же промежуток времени тормозитдо полной остановки.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout << "This program will calculate the path S traveled by the train.\n";
    "a = V/t, S1 = V*t, S2 = pow(a,t)/2, S = S1+S2.\n";
    double t;
    double V;

    do
    {
        cout << "Enter the initial starting speed : ";
        cin >> V;
        if (cin.fail())
        {
            cout << "Input error: initial starting speed must be a number.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            fflush(stdin);
        }
        else

            if (V <= 0)
            {
                cout << "Input error: initial driving speed cannot be less than zero or equal to zero.\n";
                cin.clear();
                fflush(stdin);
            }
    } while (V <= 0);

    do
    {
        cout << "Enter ride time (same as speed): ";
        cin >> t;
        if (cin.fail())
        {
            cout << "Input error: body ride time should be a number.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            fflush(stdin);
        }
        else

            if (t <= 0)
            {
                cout << "Input error: driving time cannot be less than zero or equal to zero.\n";
                cin.clear();
                fflush(stdin);
            }
    } while (t <= 0);
    double a = V / t;
    double S1 = V * t;
    double S2 = pow(a, t) / 2;
    double S = S1 + S2;
    cout << "The S way is " << S << ".";
    return 0;
}