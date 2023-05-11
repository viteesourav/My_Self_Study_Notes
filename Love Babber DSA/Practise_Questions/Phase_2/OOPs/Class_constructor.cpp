#include <bits/stdc++.h>
using namespace std;

// class -> user-defined data-type
class Demo
{

    int num1;

public:
    int num2;
    char *chArr;

    // constructor declarations.....
    Demo()
    {
        cout << "This is default Constructor" << endl;
        chArr = new char[100]; // Allocates some space to the char Array.
    }

    Demo(int num1, int num2)
    {
        cout << "paramterized constructor" << endl;
        this->num1 = num1;
        this->num2 = num2;
    }

    Demo(Demo &d)
    { // Paramter should be always passed by reference while copying an Object..
        cout << "Copy constructor" << endl;
        this->num1 = d.num1;
        this->num2 = d.num2;
        // deep Copy implementation...
        char *newChar = new char[strlen(d.chArr) + 1]; //+1 is just because we want to add a space for '\0'
        strcpy(newChar, d.chArr);                      // copy the val from source to new char array..
        this->chArr = newChar;
    }

    // Getter and Setters -> can access the private properties.
    int getNum()
    {
        return num1;
    }

    void setNum(int num)
    {
        this->num1 = num; // Pointer 'this' points to obj that called this method.
    }

    void setCharArr(char ch[])
    {
        strcpy(this->chArr, ch);
    }

    // destructor,
    ~Demo()
    {
        cout << "destructor Called" << endl;
    }
};

int main()
{

    // static declaration...
    Demo d1;
    d1.setNum(20);
    char ch[7] = "sourav";
    d1.setCharArr(ch);
    cout << d1.getNum() << endl;
    // accessing public property directly
    d1.num2 = 10;
    cout << d1.num2 << endl;

    // dynamic declaration...
    Demo *d2 = new Demo;
    d2->num2 = 40;
    d2->setNum(35);
    cout << d2->getNum() << endl;

    // paramterized constructor invokation...
    Demo d3(45, 50);
    cout << d3.getNum() << endl;

    // invoking copy constructor...
    // Demo d4(d3);
    Demo d4 = d1; // Copy assignment Opertaor, same work, copies one Object to another.
    cout << d4.getNum() << endl;

    // swallow copy, both Object points to the same memory location for pointer...
    // solution: DEfine copy Constructor instead of using the deafult one, with deep Copy feature...
    cout << "for d1 obj: " << d1.chArr << endl;
    cout << "for d4 obj: " << d4.chArr << endl;
    d1.chArr[0] = 'T';
    cout << "for d1 obj After Modification: " << d4.chArr << endl;
    cout << "for d4 obj After Modification in d1 Obj: " << d4.chArr << endl; // sourav [deep Copy implemeted] OR Tourav[swallow Copy implemented]

    // destructor of obj creatd dynamically need to call manually..
    delete d2;
    // For static Objects, destructor will be called after the scope ends for main function.

    cout << "Class and Objects-OOPS_1" << endl;
    return 0;
}