/*
Compliment of base-10 integer -> find the compliment of the number.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {

        int ans = 0, temp = n, i = 0;
        if (n == 0)
            return 1;
        while (temp != 0)
        {
            int bit = temp & 1;
            if (bit == 0)
            {
                ans += pow(2, i);
            }
            i++;
            temp = temp >> 1;
        }
        return ans;
    }
};

/*
Logic:

Approach:
    -- take the input in a temp.
    -- get the right most bit. how ? temp&1 -> gives the last bit.
    -- If this bit -> 1 (ignore because in compliment it will become zero)
       If this bit -> 0, then update ans as ans+ pow(2, step). [step -> keeps count of iteration]
    -- update temp as temp>>1 -> move all bits towards right.
*/