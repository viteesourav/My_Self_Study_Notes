#include <bits/stdc++.h>
using namespace std;

// reversing the String
void reverseStr(string &str, int start, int end)
{
    cout << str << " " << start << " " << end << endl;
    // baseCase:
    if (start > end)
        return;

    // will swap the current index of start and end.
    swap(str[start], str[end]);
    // updating the start and end.
    start++;
    end--;
    return reverseStr(str, start, end);
}

// More Optimised code using one pointer...
void reverseStr2(string &str, int index = 0)
{
    cout << str << " " << index << " " << str.length() - 1 - index << endl;
    // baseCase:
    if (index > str.length() - 1 - index)
        return;

    // will swap the current index of start and end.
    swap(str[index], str[str.length() - 1 - index]);
    // updating the start and end.
    index++;
    return reverseStr(str, index);
}

int main()
{
    string str = "sourav";
    reverseStr(str, 0, str.length() - 1);
    cout << str << endl;

    cout << "String Recusrssion" << endl;
    return 0;
}
