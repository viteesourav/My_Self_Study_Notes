/*
This is a classic case of Calling Recursion inside a for-loop. ans basic back-tracking method.
Letter combination of a phone number:
Given a string, as number pressed in the keypad, all possible characters...
*/

class Solution
{

private:
    // This function we will call recursively and find all possible
    void solve(string digits, string output, int index, vector<string> &ans, string mappings[])
    {

        // baseCase: When the index exceeds the len of digit.
        if (index >= digits.length())
        {
            // InCase nothing is passed to digit...
            if (digits.length() < 1)
                return;
            ans.push_back(output); // pushing whatever the ouput stores in ans.
            return;
        }

        // fetch the mapped keys with the digit at index.
        string mapKeys = mappings[digits[index] - 48];

        // for each keys, call the function recursively..
        for (int i = 0; i < mapKeys.length(); i++)
        {
            output.push_back(mapKeys[i]);                    // add the current key to the output.
            solve(digits, output, index + 1, ans, mappings); // call the function recursively...
            // Remove the current key that was added
            // next loop instance we want to add new key to the ouput, thus, poping the old one.
            output.pop_back(); // this is what we are doing is called back-tracking.[IMP]
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {

        vector<string> ans;
        string output;
        // storing the keypad mapping...
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, 0, ans, mapping);
        return ans;
    }
};

/*

Logic:


2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz


Pressed: 23

strings: abc def, need a pattern of 2 characters.

output: ab ac ad ae af, bc, bd, be, bf, cd, ce, cf - all possible subsets with 2 char, no-repeating.

Logic:
-- Store the keypad mapping in a string array.
-- then start with the given digit first number.
-- get the mapping from the string array and call the fucntion recursively by including each character in the output.




*/