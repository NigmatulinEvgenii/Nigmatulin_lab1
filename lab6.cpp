#include <string>
#include <iostream>
 
using namespace std;
 
struct obj {
    string name;
    int type;
    obj* point1, * point2;
    void point() {
        if (point1 || point2) {
            if (type == 1)
                cout << "Name: " << name << " Pointers: " << point1->name << ", " << point2->name << endl;
            if (type == 2)
                cout << "Name: " << name << " Pointer: " << point1->name << endl;
        }
        else
            cout << "Name: " << name << " Pointer: nothing" << endl;
    }
};
 
int main() {
    obj obj1, obj2, obj3, obj4, obj5, obj6;
    obj1 = { "1", 1, &obj2, &obj3 };
    obj2 = { "2", 2, &obj4 };
    obj3 = { "3", 2, &obj5 };
    obj4 = { "4", 2, &obj6 };
    obj5 = { "5", 2, &obj6 };
    obj6 = { "6", 1 };
 
    obj1.point();
    obj2.point();
    obj3.point();
    obj4.point();
    obj5.point();
    obj6.point();
}
