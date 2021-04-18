#include <iostream>

using namespace std;

double getDouble();
int getInt();

const double pi = 3.1415;

class TrigForm;

class ExpForm {
public:
    void print();
    void setComplex();
    void translate(TrigForm trigForm);
    double getA();
    double getB();
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
    double absb; // abs - модуль, а в формуле |b| - длинна отрезка.
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
    //if (abs(cos) != abs(sin))
        //cout << "Calcucations may be incorrect, because cos = " <<  cos << ", sin = "<< sin << endl;
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


int main() {
    Complex number;
    number.setOneForm();
    number.printComplexNumber();
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