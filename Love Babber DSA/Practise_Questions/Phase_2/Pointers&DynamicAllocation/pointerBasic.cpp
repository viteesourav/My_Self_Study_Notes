// single pointer and double pointer implementation
#include <bits/stdc++.h>
using namespace std;

void print(int *);
void update(int *);
void updatePtr(int **);
int getSum(int *, int);

int main()
{

    int num = 5;
    cout << &num << endl; // address of num

    int *ptr = &num; // can hold a address.
    cout << ptr << " " << *ptr << endl;

    // pointer operations
    (*ptr)++;
    cout << *ptr << endl;
    *ptr = *ptr + 1;
    cout << *ptr << endl;

    // copying an existing ppointer
    int *qtr = ptr;
    cout << qtr << " " << *qtr << endl;
    cout << ptr << " " << *ptr << endl;

    int **q = &ptr; // double pointer
    cout << q << " " << *q << " " << **q << endl;

    int num = 10;
    cout << num << " " << &num << endl;
    int *ptr = &num;
    cout << ptr << " " << *ptr << endl;
    int **str = &ptr;
    cout << str << " " << **str << endl;

    // Integer Arrays and Pointers
    int arr[] = {1, 2, 3, 4, 5, 6};

    cout << arr << " " << *arr << endl;
    cout << (arr + 1) << " " << *(arr + 1) << endl;
    cout << 3 [arr] << " " << *(3 + arr) << endl;
    // arr = arr + 1; this will give error. As per symbol Table we cannot update.
    int *ptr = arr;
    cout << ptr << " " << *ptr << endl;
    ptr = ptr + 1;
    cout << ptr << " " << *ptr << endl;

    // character arrays
    char str[5] = {'a', 'b', 'c', 'd'};

    cout << str << " " << *str << endl;           // abcd a
    cout << str + 1 << " " << *(str + 1) << endl; // bcd b

    // in case of pointer pointing to a static char
    char temp = 'x';
    char *str2 = &temp;
    // cout<<str2<<endl; //prints weirdly, since it will keep on printing till it gets a '\0' in memory.

    // Pointer and chars with specified length
    char temp2[6] = "abcde";  // len is more to accomodate '\0' character.
    cout << temp2[5] << endl; // it has '\0'-> new line character.
    cout << temp2 << endl;
    char *t2 = &temp2[0]; // This how you use pointer on char array.
    cout << t2 << endl;

    // This how you should never handle pointers and string
    char *ch = "sourav";
    cout << ch << endl;

    // funcitons and Pointers
    int num = 5;
    int *p = &num;
    // print(p);
    cout << p << " " << *p << endl; // 100 5
    update(p);                      // pasing by Value
    cout << p << " " << *p << endl; // 100 6

    // arrays
    int arr[5] = {1, 2, 3, 4, 5};
    cout << getSum(arr, 5) << endl;
    cout << getSum(arr + 3, 2) << endl; // sends a part of the arr i.e Benfit of passing array by refernece.

    // double-pointers and functions
    int num = 5;
    cout << num << " " << &num << endl; // 5 100
    int *ptr = &num;
    updatePtr(&ptr); // address of ptr say 200 [pssign by reference since am passing the address]
    cout << ptr << " " << *ptr << endl;

    return 0;
}

void print(int *p)
{
    cout << p << " " << *p << endl;
}

void update(int *p)
{
    // p = p+1;
    // cout<<p<<" "<<*p<<endl; //104 garbage value
    (*p)++;
}

int getSum(int arr[], int n)
{
    cout << "Size of array inside Fun: " << sizeof(arr) << endl; // prints 8
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

void updatePtr(int **p)
{ // address of double pointer say 300
    // p=p+1;
    // cout<<p<<" "<<*p<<endl; // 304 garbage address Val
    // *p += 1;
    // cout<<p<<" "<<*p<<endl; //204 and some garbage val
    **p += 1;
    cout << p << " " << **p << endl; // 104 and 6
}