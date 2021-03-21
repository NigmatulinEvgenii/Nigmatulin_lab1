#include <iostream>

using namespace std;

int getSize()
{
    while (true)
    {
        cout << "Enter the number of measurements i: ";
        int i;
        cin >> i;
        if ((cin.fail()) || (i < 2))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "i - number. \n";
            }
            else
            {
                cout << "i cannot be less 2. \n"; 
            }
        }
        else
        {
            cin.ignore(32767, '\n');
            return i;
        }
    }
}

double getValue()
{
    while (true)
    {
        double i;
        cin >> i;
        if ((cin.fail()) || (i < 0))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "E - number. \n";
            }
            else
            {
                cout << "this value cannot be less 0. \n";
            }
        }
        else
        {
            cin.ignore(32767, '\n');
            return i;
        }
    }
}

double getProbability()
{
    while (true)
    {
        double i;
        cin >> i;
        if ((cin.fail()) || ((i >= 1) || ( i <= 0 )))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "P - number. \n";
            }
            else
            {
                cout << "notice, that 0 < P < 1. \n";
            }
        }
        else
        {
            cin.ignore(32767, '\n');
            return i;
        }
    }
}

int main()
{
    int i = getSize();
    double *numbers = new double[i];

    for (int k = 0; k < i; k++)
    {
        cout << "number e_" << k+1 << ": ";
        numbers[k] = getValue();
    }

    double *probabilities = new double[i];
    double prob_sum = 0;

    do {
        for (int k = 0; k < i; k++)
        {
            cout << "probability P_" << k + 1 << ": ";
            probabilities[k] = getProbability();
            prob_sum += probabilities[k];
        }

        if (prob_sum != 1)
        {
            cout << "Your sum of probabilities is: " << prob_sum << ". Enter these values p, so that the sum of the probabilities is equal to 1 \n";
            prob_sum = 0;
        }
    } while (prob_sum != 1);

    double exceptation = 0;
    double exceptation_square = 0;

    for (int k = 0; k < i; k++)
    {
        exceptation += numbers[k] * probabilities[k];
        exceptation_square += numbers[k] * numbers[k] * probabilities[k];
    }

    cout << "The variance of a given value is: " << exceptation_square - exceptation * exceptation;

    delete[] numbers;
    delete[] probabilities;

    return 0;
}