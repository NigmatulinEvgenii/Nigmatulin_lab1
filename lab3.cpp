#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct DLoRV //The distribution law of a random variable
{
    vector<int> values;
    vector<int> probability;
};

int getInt();
DLoRV getDLoRV();
double getExpValue(DLoRV dlorv, int power);
void outputDLoRV(DLoRV dlorv);

int main()
{
    DLoRV dlorv;
    dlorv = getDLoRV();
    double dispersion = getExpValue(dlorv, 2) - pow(getExpValue(dlorv, 1), 2);
    outputDLoRV(dlorv);
    cout << "Dispersion: " << dispersion << endl;
    return 0;
}

int getInt() {
    while (true) {
        int number;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            return number;
        }
    }
}

DLoRV getDLoRV()
{
    DLoRV dlorv;
    double sumProbability = 0;
    while (sumProbability != 100) {
        cout << "Enter value and probability [0;" << 100 - sumProbability << "]:";
        int prob;
        dlorv.values.push_back(getInt());
        while (true) {
            prob = getInt();
            if ((prob <= 100 - sumProbability) && (prob >= 0))
                break;
            else
                cout << "Enter probability again [0;" << 100 - sumProbability << "]:" << endl;
        }
        sumProbability += prob;
        dlorv.probability.push_back(prob);
        cin.ignore(32767, '\n');
    }
    return dlorv;
}

double getExpValue(DLoRV dlorv, int power) { // Expected value
    int lenght = 0;
    double expValue = 0;
    lenght = dlorv.probability.size();
    for (int i = 0; i < lenght; i++) {
        expValue += pow(dlorv.values[i], power) * (dlorv.probability[i] / 100.0);
    }
    return expValue;
}

void outputDLoRV(DLoRV dlorv) {
    int lenght = dlorv.probability.size();
    cout << "Values and probability: " << endl;
    for (int i = 0; i < lenght; i++) {
        cout << dlorv.values[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < lenght; i++) {
        cout << dlorv.probability[i] / 100.0 << " ";
    }
    cout << endl;
}