#include <bits/stdc++.h>
using namespace std;

// check Palindrome
bool checkPalindormStr(string str, int index = 0)
{

    // baseCase:
    // One more edge case..
    if (str.length() < 2)
        return true; // if the str has only one char or nothing
    // If till the baseCase if the base case reached then its a palindrome String
    if (index > str.length() - 1 - index)
        return true;

    // if it don't match then return false.
    if (str[index] != str[str.length() - 1 - index])
        return false;

    // update the index.
    index++;
    return checkPalindormStr(str, index);
}

int main()
{
    string str = "kiik";
    cout << checkPalindormStr(str) << endl;

    cout << "String Recusrssion" << endl;
    return 0;
}