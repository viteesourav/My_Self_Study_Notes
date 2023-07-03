// Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
/*
Basically, You given n people attends the party. Now among N people, 1 person is such that,
    He dont know anyone but everyone knows him.
We need to find this person ?
Note: the above situation is given in form of matrix where row and col are people index and if 1 then they know each othre, 0 they dont know.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // we will solve this stack appraoch...
        //[AT end stack should contains the id of the celebrity person's index id]

        stack<int> st;

        // put indexes of the people attedning the party in stack..
        for (int i = 0; i < n; i++)
            st.push(i);

        // Now till the stack has 1 element, take 2 people and check if they know each other
        while (st.size() > 1)
        {

            int person1 = st.top(); // person 1
            st.pop();

            int person2 = st.top(); // person 2
            st.pop();

            // check if person1 knows person2 or not ?
            if (M[person1][person2] == 1)
                st.push(person2); // p1 knows p2, then push p2 as he wont know p1
            else
                st.push(person1); // p2 knows p1, then push p1, as he wont know p2.
        }

        // Now you will have possible celebrity index left in stack..
        int celebrity = st.top();

        // verify if this guy is celebrity or not ?
        // condition: 1) He should not know any one i.e all elements 0
        //            2) Everyone should know him i.e all elements 1 [except diagonal]

        // check the row..
        for (int j = 0; j < n; j++)
        {
            if (M[celebrity][j] == 1)
                return -1; // In Row all elements should be 0, If we get 1 then he is not celebrity
        }

        // check the column..
        for (int i = 0; i < n; i++)
        {
            if (i != celebrity && M[i][celebrity] == 0)
                return -1; // In column all elements should be 1[except diag], if we get 0 then he is not celebrity
        }

        // If it passes the above elemenation creteria..Then he is a celebrity
        return celebrity;
    }
};

/*
Appraoch/Logic:

Identify the Celebrity

2 Condition should satisfy for the celebrity:
1) Who ever is the celebrity don't know anyone.
2) Other people knows celebrity.

Note: Ignore the digonal elements as Everyone will know themselves..

i  0   1   2  --> peopleId
0  0   1   0
1  0   0   0
2  0   1   0


Here, the 1st Row knows noone, but all people knows 1st Row[From column]


Appraoch:

1) Brute Force Approach: TC: O(n2) SC: O(1)

   -- For ith index, check:
      all elements should be 0 for ith Row [ignore diagonal element]
      all elements should be 1 for ith column [ignore diagonal element]

   If for anyRow this condition satisfy then ith Row is celebrity. else NOt !

2) Using stack:

   -- In the stack, only the celebrity will remain at the end [as per algo]

  Appraoch:  TC: O(n)  SC: O(n)

   -- First of all put ids of all People [indexs of Rows] in the stack.

   -- Now till the stack has just 1 element,
      -- POP two element from stack. say A and B.
      -- Check if A knows B if yes, then push B back, else Push A back.
   -- At the ened just one element remanins in stack. say K [our possible celebrity]

   -- Now verify the celebrity condition for Kth index.
      -- For Kth Row, He should not know any other person.[All should be zero]
      -- For Kth Col, All should know Kth Person.[except digonal element][All should be 1]

   -- If all statisfy then K is celebrity [ans]
      else celebrity dosnot exist.

*/