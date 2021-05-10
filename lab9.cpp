#include <string>
#include <iostream>

using namespace std;

struct Obj {
    string name;
    int type;
    Obj* point1, * point2;
    void point();
};

void Obj::point()
{
    if (point1 || point2) {
        if (type == 1)
            cout << "Name: " << name << " Pointers: " << point1->name << ", " << point2->name << endl;
        if (type == 2)
            cout << "Name: " << name << " Pointer: " << point1->name << endl;
    }
    else
        cout << "Name: " << name << " Pointers: nothing" << endl;
}

struct Tree {
public:
    Tree(int numberOfLayers);
    void print();
private:
    int numberOfLayers;
    int numberOfObj;
    Obj* objs;
};

Tree::Tree(int numberOfLayers)
{
    this->numberOfLayers = numberOfLayers;

    if (numberOfLayers == 1 || numberOfLayers == 2)
        numberOfObj = numberOfLayers;
    else
        numberOfObj = (numberOfLayers - 2) * 2 + 2;

    objs = new Obj[numberOfObj];
    objs[0] = { "obj1", 1 };
    if (numberOfObj > 1)
        objs[numberOfObj - 1] = { "obj" + to_string(numberOfObj), 1 };
    if (numberOfObj > 2)
        for (int i = 1; i < numberOfObj - 1; i++)
            objs[i] = { "obj" + to_string(i + 1), 2 };

    if (numberOfObj == 2) {
        objs[0].point1 = &objs[1];
        objs[0].point2 = &objs[1];
    }
    else if (numberOfObj > 2) {
        objs[0].point1 = &objs[1];
        objs[0].point2 = &objs[2];
        for (int i = 1; i < numberOfObj - 1; i++)
            if (i + 2 != numberOfObj)
                objs[i].point1 = &objs[i + 2];
            else
                objs[i].point1 = &objs[i + 1];
    }
}

void Tree::print() {
    for (int i = 0; i < numberOfObj; i++)
        objs[i].point();
}

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
    int numberOfLayers = 0;
    cout << "Input numbers of layers: ";
    while (true) {
        numberOfLayers = getInt();
        if (numberOfLayers < 0) {
            cout << "Number of layers must be > 0: ";
            continue;
        }
        else
            break;
    }
    Tree tree(numberOfLayers);
    tree.print();
}