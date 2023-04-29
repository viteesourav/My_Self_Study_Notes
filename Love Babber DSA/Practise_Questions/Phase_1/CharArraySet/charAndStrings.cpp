#include <bits/stdc++.h>
using namespace std;

// returns the len of str using '\0'...
int findStrLen(char str[])
{

    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    // cout<<"Length: "<<i<<endl;
    return i;
}

// Get the reverse of the given str...
void reverseStr(char str[])
{
    int len = findStrLen(str);
    int l = 0, h = len - 1;
    while (l < h)
    {
        swap(str[l], str[h]);
        l++;
        h--;
    }
    cout << str << endl;
}

// check if the str is alphanumric and if it is palindrom...
bool ispalindrom(string str)
{

    int l = 0, h = str.length() - 1;
    while (l < h)
    {

        if (!iswalnum(str[l]))
            l++;
        else if (!iswalnum(str[h]))
            h--;
        else if (tolower(str[l++]) != tolower(str[h--]))
            return false;
    }
    return true;
}

// reverse each word in the string at its place and return the modified reverse String.
string doReverse(string str)
{
    int l = 0, h = str.length() - 1;
    while (l < h)
        swap(str[l++], str[h--]);
    return str;
}

string reverseWords(string s)
{

    string ans;
    int i = 0, start = 0;
    while (i < s.length())
    {
        if (s[i] == ' ')
        {
            ans.append(doReverse(s.substr(start, i - start)));
            ans.append(" ");
            start = i + 1;
        }
        i++;
    }
    ans.append(doReverse(s.substr(start, i - start))); // For the last word.
    return ans;
}

// find the max occuringChar
char highestOccurringChar(char input[])
{
    // Write your code here
    int charArr[26] = {0}; // This is a flat freq table, starts from 0 to 25, 0 -->'a' and 25 --> 'z'
    for (int i = 0; input[i] != '\0'; i++)
    { // as it hits its increment at the resp post in freq table.
        charArr[input[i] - 'a']++;
    }
    int maxPost = 0; // minding the index with max value.
    for (int i = 0; i < 26; i++)
    {
        if (charArr[i] > charArr[maxPost])
            maxPost = i;
    }
    return 'a' + maxPost;
}

int main()
{

    // char str[20];
    // cin>>str;
    // findStrLen(str);
    // reverseStr(str);
    // cout<<ispalindrom("A man, a plan, a canal: Panama")<<endl;

    // string str = "sourav";
    string str("sourav"); // since String is a class, so i can use the constructor.
    // cin>>str;
    for (int i = 0; i < str.length(); i++)
        cout << str[i] << " ";
    cout << endl;

    cout << "Char Arrays" << endl;
}