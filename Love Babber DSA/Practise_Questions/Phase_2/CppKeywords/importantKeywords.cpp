#include <bits/stdc++.h>
using namespace std;

// using macros in code reduce time and faster.
#define PI 3.14
#define SQUARE(x) (x * x); // In code it replaces square(x) with x*x
#define MIN_VAL(a, b) ((a < b) ? a : b)

// global var
int temp = 56;

int main()
{

    int radius;
    cin >> radius;

    // calling the above macro in the prog.
    float area = PI * SQUARE(radius);
    cout << "Area of Circle is: " << area << endl;

    // minimum.
    int a, b;
    cin >> a >> b;
    cout << "Min is: " << MIN_VAL(a, b) << endl;

    // uSING GLOBALS
    int temp = 45;
    cout << "Local Vaiable: " << temp << endl;    // 45
    cout << "Global Vriable: " << ::temp << endl; // 56

    cout << "C++ keywords" << endl;
    return 0;
}