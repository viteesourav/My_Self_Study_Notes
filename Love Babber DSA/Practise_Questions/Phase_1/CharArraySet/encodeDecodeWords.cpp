/*
    Link: https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1 [medium]
    encode the words ==> ["Neet", "code"] ==> encodedv1 ==> decode the words ===> ["Neet", "code"]
*/

class Solution
{
public:
    // Encoding Logic: <lenOfWord>#<word> for each word..
    string encode(vector<string> &s)
    {
        // code here
        string str;
        for (string st : s)
            str.append(to_string(st.length()) + "#" + st);

        // cout<< str;
        return str;
    }

    vector<string> decode(string &s)
    {

        vector<string> ans;
        int i = 0;

        // iterate the string...
        while (i < s.length())
        {
            // extract the count..
            int j = i;

            while (s[j] != '#')
                j++;
            int len = stoi(s.substr(i, j - i)); // from i -> start index, j-i => len of the word ==> gives count. eg: 25#word => we extract 25.
            string word = s.substr(j + 1, len); // j+1 => start pos, len => total word length.
            ans.push_back(word);

            // update your i...
            i = j + 1 + len;
        }
        return ans;
    }
};

/*
Approach: TC: O(n)
    
    Encoding Logic: 
        1. For each word => update the word as <lenOfWord>#<word> 

    Decoding logic:
        1. First extract the len of the word. [NOTE: could be more than 1 digit]
            -> use i and j loop to extract the word [string] => convert it the int.
        2. Extract the word itself using str.substr<startPos, lenOfWord>  ==> add in the ans list.
        3. Update the i to the next wword's starting.

*/