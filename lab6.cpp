#include <string>
#include <iostream>

using namespace std;

struct Obj {
    string name;
    int type;
    Obj* point1, * point2;
    void point() {
        if (point1 || point2) {
            if (type == 1)
                cout << "Name: " << name << " Pointers: " << point1->name << ", " << point2->name << endl;
            if (type == 2)
                cout << "Name: " << name << " Pointer: " << point1->name << endl;
        }
        else
            cout << "Name: " << name << " Pointers: nothing" << endl;
    }
};

int getInt()
{
    int number;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Do input again." << endl;
        }
        else
            return number;
    }
}

int main() {
    int n = 0;
    int number;
    Obj* obj;
    cout << "Input numbers of layers: ";
    while (true) {
        n = getInt();
        if (n < 0) {
            cout << "Number of layers must be > 0: ";
            continue;
        }
        else
            break;
    }
    if (n == 1 || n == 2)
        number = n;
    else
        number = (n - 2) * 2 + 2;

    obj = new Obj[number];

    obj[0] = { "obj1", 1 };
    if (number > 1)
        obj[number - 1] = { "obj" + to_string(number), 1 };
    if (number > 2)
        for (int i = 1; i < number - 1; i++)
            obj[i] = { "obj" + to_string(i + 1), 2 };

    if (number == 2) {
        obj[0].point1 = &obj[1];
        obj[0].point2 = &obj[1];
    }
    else if (number > 2) {
        obj[0].point1 = &obj[1];
        obj[0].point2 = &obj[2];
        for (int i = 1; i < number - 1; i++)
            if (i + 2 != number)
                obj[i].point1 = &obj[i + 2];
            else
                obj[i].point1 = &obj[i + 1];
    }

    for (int i = 0; i < number; i++)
        obj[i].point();
}