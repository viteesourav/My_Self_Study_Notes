// This File contains, Practise while learning the pillars of OOps...
#include <bits/stdc++.h>
using namespace std;

class A
{

public:
    int prop1 = 10;

public:
    int getClassProperty()
    {
        return this->prop1;
    }
};

class B : protected A
{
public:
    int prop2 = 20;

public:
    int getClassProperty()
    {
        return this->prop2;
    };

    int getProp1()
    {
        return this->prop1;
    }
};

class C : protected B
{
    int prop3 = 30;

protected:
    int getProp3()
    {
        return this->prop3;
    }
};

// Polymorphism...
class D
{

public:
    int prop4 = 40;

    // function Overloading
    void sayHi()
    {
        cout << "Hi" << endl;
    };
    void sayHi(string name)
    {
        cout << "Hi " << name << endl;
    };
};

// Operator_Overloading...
class Complex
{
public:
    int real;
    int imag;

public:
    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    };

    // Operator_Overloaded '+'
    Complex operator+(Complex &c)
    {
        Complex res(0, 0);
        res.real = this->real + c.real;
        res.imag = this->imag + c.imag;
        return res;
    };

    void printComplex()
    {
        cout << this->real << "+ i" << this->imag << endl;
    }
};

int main()
{

    // B obj1;
    // // cout<<obj1.prop1<<endl;
    // cout<<obj1.getClassProperty()<<endl;

    // Handling Ambigious Inheritance -> multiple Inheritance..
    //  C obj2;
    //  cout<<obj2.A::getClassProperty()<<endl;
    //  cout<<obj2.B::getClassProperty()<<endl;

    // Polymorphism
    //  D obj4;
    //  obj4.sayHi();
    //  obj4.sayHi("sourav");

    // ObjectOverloading...
    //   Complex c1 (2, 3);
    //   c1.printComplex ();
    //   Complex c2 (4, 5);
    //   c2.printComplex ();
    //   Complex c3 = c1+c2; //+ Operator is overloaded here...
    //   c3.printComplex();

    // Checkingt the scope of protected scope.
    B obj;
    cout << obj.getProp1() << endl;
    C obj2;
    // cout<<obj2.getProp1()<<endl;
    // cout<<obj2.getProp3()<<endl;  //protected members cannot be accessed...

    return 0;
}
