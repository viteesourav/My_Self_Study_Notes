#include <bits/stdc++.h>
using namespace std;

// calling update by value i.e a copy is created.
void update(int n)
{
    n++;
}

// calling update using a reference i.e a reference to the same memory location is created.
void update2(int &n)
{
    n++;
}

int main()
{

    int i = 5;
    cout << i << " " << &i << endl;

    // creating a refernce variable for i
    int &j = i;
    cout << j << " " << &j << endl;

    // using a reference varaible in funciton
    int num = 5;
    cout << num << endl;
    update(num);  // Here call by value,
    update2(num); // here call by refernce
    cout << num << endl;

    // In c++ we use 'new' keyword to access the heap memory and dynamically create storage space.
    int n;
    cin >> n;
    int *arr = new int[n]; // creating space in heap
    // accpet input..
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // print array vlaues.
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr; // manually free the memory from heap memory.

    // Dynamic 2-D Array creation.
    int m, n;
    cin >> m >> n;

    // creating 2D Array in runTime.
    int **arr = new int *[m];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // filling all elements with 0.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    // printing the arr
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // for freeing memory;
    for (int i = 0; i < m; i++)
    {
        delete[] arr[i]; // This release all columns as per columns
    }
    delete[] arr; // this release all the rows

    return 0;
}