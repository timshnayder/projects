#include <iostream>
#include <memory>

using namespace std;
class A {
public:
    A() {
        cout << "Constructor" << endl;
    }
    void print() {
        cout << "Print" << endl;
    }
    ~A() {
        cout << "Destructor" << endl;
    }
};
int main() {
    int a[] = { 1, 2, 10 };
    int *p = a;
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p++;
    cout << *p << endl;
    *(a + 1) = 20;
    p--;
    cout << *p << endl;
//    if (true) {
//        unique_ptr<A> a(new A);
//        a->print();
//        cout << "In the code" << endl;
//    }
    return 0;
}
