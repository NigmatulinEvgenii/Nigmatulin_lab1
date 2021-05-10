#include <iostream>
#include <math.h>

using namespace std;


template < typename T >
double getExp(T number);
double getDouble();
int getInt();
long long int fact(int number);

const double pi = 3.1415;

class TrigForm;

class ExpForm {
public:
    void print();
    void setComplex();
    void translate(TrigForm trigForm);
    double getA();
    double getB();
    void setAB(double a, double b);
private:
    double a, b;
};

class TrigForm {
public:
    void print();
    void setComplex();
    void translate(ExpForm expForm);
    double getAbsb();
    double getPhi();
private:
    double absb;
    double phi;
};

void ExpForm::print() {
    cout << "Exponential form of a complex number is: " << a << " + " << b << " * i" << endl;
}

void ExpForm::setComplex() {
    cout << "Enter a of a + b * i: ";
    a = getDouble();
    cout << "Enter b of a + b * i: ";
    b = getDouble();
}

void ExpForm::translate(TrigForm trigForm) {
    a = cos(trigForm.getPhi()) * trigForm.getAbsb();
    b = sin(trigForm.getPhi()) * trigForm.getAbsb();
}

double ExpForm::getA() {
    return a;
}

double ExpForm::getB() {
    return b;
}

void ExpForm::setAB(double a, double b)
{
    this->a = a;
    this->b = b;
}

void TrigForm::print() {
    cout << "Trigonometric form of a complex number is: " << absb << " * (cos(" << phi << ") + i * sin(" << phi << ")" << endl;
}

void TrigForm::setComplex() {
    cout << "Enter |b| of |b| * (cos(phi) + i * sin(phi): ";
    absb = getDouble();
    cout << "Enter phi of |b| * (cos(phi) + i * sin(phi): ";
    phi = getDouble();
}

void TrigForm::translate(ExpForm expForm) {
    absb = sqrt(pow(expForm.getA(), 2) + pow(expForm.getB(), 2));
    double cos = acos(expForm.getA() / absb);
    double sin = asin(expForm.getB() / absb);
    double rawPhi = abs(sin);
    if (sin > 0 && cos > 0)
        phi = rawPhi;
    else if (sin < 0 && cos>0)
        phi = -rawPhi;
    else if (sin < 0 && cos < 0)
        phi = -pi + rawPhi;
    else if (sin > 0 && cos < 0)
        phi = pi - rawPhi;
    else
        phi = rawPhi;
}

double TrigForm::getAbsb() {
    return absb;
}

double TrigForm::getPhi() {
    return phi;
}

class Complex {
public:
    void setOneForm();
    void printComplexNumber();
    void complexExponent();
private:
    ExpForm expForm;
    TrigForm trigForm;
};

void Complex::setOneForm() {
    cout << "Choise form of Complex number" << endl << "1 - Exp" << endl << "2 - Trig" << endl;
    int type;
    while (true) {
        type = getInt();
        if (type == 1 || type == 2)
            break;
        else
            cout << "Wrong input, please enter 1 or 2:";
    }
    switch (type) {
    case 1:
        expForm.setComplex();
        trigForm.translate(expForm);
        break;
    case 2:
        trigForm.setComplex();
        expForm.translate(trigForm);
        break;
    default:
        break;
    }
}

void Complex::printComplexNumber() {
    expForm.print();
    trigForm.print();
}

void Complex::complexExponent()
{
    Complex result;
    result.expForm.setAB(getExp<double>(expForm.getA()), getExp<double>(expForm.getB()));
    result.trigForm.translate(result.expForm);
    result.printComplexNumber();
}


int main() {
    Complex number;
    number.setOneForm();
    cout << "You entered" << endl;
    number.printComplexNumber();
    cout << "Exp";
    number.complexExponent();
    return 0;
}

double getDouble() {
    while (true) {
        double number;
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

template < typename T >
double getExp(T number) {
    number = -number;
    double result = 0;
    for (int i = 0; i < 15; i++) {
        double temp;
        temp = pow(-1, i) * pow(number, i);
        temp = temp / fact(i);
        result += temp;
    }
    return result;
}

long long int fact(int number) {
    if (number < 0)
        return 0;
    else if (number == 0 || number == 1)
        return 1;
    else return number * fact(number - 1);
}