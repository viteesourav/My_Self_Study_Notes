#include <bits/stdc++.h>
using namespace std;

void binarySearchAlgo()
{

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(9);

    cout << binary_search(v.begin(), v.end(), 9) << endl; // true since Found.
    cout << binary_search(v.begin(), v.end(), 0) << endl; // false since not Found.

    int post = lower_bound(v.begin(), v.end(), 6) - v.begin();
    cout << "post is: " << post << endl;
}

void minAndMaxAndsWap()
{

    int a = 10, b = 6;

    cout << min(a, b) << endl;
    cout << max(a, b) << endl;

    swap(a, b);
    cout << "a:" << a << " b:" << b << endl;
}

void reverseSTL()
{

    string str = "abcde";
    reverse(str.begin(), str.end());
    cout << str << endl;
}

void rotateSTL()
{

    vector<int> v;

    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    rotate(v.begin(), v.begin() + 1, v.end()); // Roatate at index 1.

    for (auto it : v)
        cout << it << " ";
    cout << endl;

    sort(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{

    // Algorithm Set ....
    // binarySearchAlgo();
    // minAndMaxAndsWap();
    // reverseSTL();
    rotateSTL();

    cout << "STL WorkThrough..." << endl;
    return 0;
}