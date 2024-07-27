// this shows the cascade increment hell
#include <bits/stdc++.h>
using namespace std;

//function to understand cascade increment and decrement Operators...
void test_cascadeOperation() {
    
    int i = 5, a = 0;
    
    //######alone increment post and pre..
    int x = i++; cout<<x<<" "<<i<<endl;
    int y = ++i; cout<<y<<" "<<i<<endl;
    cout<<x+y<<endl<<endl;
    
    //######with both pre..
    int x = ++i; cout<<x<<" "<<i<<endl;
    int y = ++i; cout<<y<<" "<<i<<endl;
    cout<<x+y<<endl<<endl;
    
    i = 7;
    cout<<i<<endl; //i: 7
    a = (++i)+(++i); //++i ==> 8 and ++i ==> 9, 8+9 = 17, i-->9 correct: 18
    cout<< a <<endl;
    
    //####with both post..
    i = 7;
    cout<<i<<endl; //i: 7
    a = (i++)+(i++); //i++ ==> 7 and i++ ==> 8, 7+8 = 15, i --> 9
    cout<< a << " " << i<<endl;
    
    //####pre and post...
    i = 7;
    cout<<i<<endl; //i: 7
    a = (++i)+(i++); //i++ ==> 7 and ++i ==> 9, 7+9 = 16, i --> 9, Correct: 17
    cout<< a << " " << i<<endl;
    
    // post and pre...
    i = 7;
    cout<<i<<endl; //i: 7
    a = (i++)+(++i); //++i ==> 8 and i++ ==> 8, 8+8 = 16, i --> 9
    cout<< a << " " << i<<endl;  
}

/*
conclusion: 
    Using the same variable as cascading ++i and i++ causes amiguity, the result will be offset by 1 based on the order of pre and post increment operator..
*/

int main()
{

    int i = 5, a = 0;

    int x = (++i);
    int y = (i++);
    cout << (x + y) << endl; // output is 12

    i = 5;
    a = (++i) + (++i);
    cout << a << " " << i << endl; // output is 14 7

    i = 5;
    a = (i++) + (++i);
    cout << a << " " << i << endl; // output is 12 7

    i = 5;
    a = (++i) + (i++);
    cout << a << " " << i << endl; // output is 13 7

    return 0;
}

/* Observation:
In Increment whenever you do it in a single line, 1 is getting added to the end-result.
In Decrement the end result is always coming 1 short.

Reason: 
    lets observe this: a = (++i) + (++i);  
        -- Lets say i = 7;
        -- ++i --> 8, then again ++i --> 9 then, You add 2 values of i --> 9 + 9 ==> 18.
        -- The same variable, You are updating 2 times, When add is performed, It takes the last updated value of i.
        -- Thus the sum is (9 + 9) ==> 18.

*/