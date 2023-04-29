// this shows the cascade increment hell
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i = 5, a = 0;

    int x = (++i);
    int y = (i++);
    cout << (x + y) << endl; // output is 12

    i = 5;
    a = (++i) + (i++); // output is 13

    cout << a << " " << i << endl;

    return 0;
}

/* Observation:
In Increment whenever you do it in a single line, 1 is getting added to the end-result.
In Decrement the end result is always coming 1 short.
*/