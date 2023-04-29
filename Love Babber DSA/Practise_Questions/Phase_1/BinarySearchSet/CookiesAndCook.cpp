// Very very Important Cookie and cook Question.
#include <bits/stdc++.h>
using namespace std;

// As per rating how much time Cooks takes to back n cookies
int findTimeTakenToCook(int Ratings, int n)
{
    return Ratings * ((n * (n + 1)) / 2);
}

// This checks if all the cookies can be delivered within the given time or not ?
bool isJobFinished(vector<int> &rank, int reqCookies, int midTime)
{

    int totalCookieCount = 0;
    for (int i = 0; i < rank.size(); i++)
    {
        int cookRating = rank[i];
        int cookieCount = 1, timeTaken = 0;
        while (findTimeTakenToCook(cookRating, cookieCount) <= midTime)
        {
            cookieCount++;
        }
        totalCookieCount += (cookieCount - 1); // CookieCount -1 because above using a while loop, so it will increase the count and then compare if it false it comes out, then we need to go back to the old value as cookie-1
    }
    if (totalCookieCount >= reqCookies)
        return 1;
    else
        return 0;
}

int minCookTime(vector<int> &rank, int m)
{
    // lets find the solution space first...
    int l = 0, h = findTimeTakenToCook(10, m); // 10 is max possible rating and m is the needed number of cookies
    int ans = -1;
    // stating the BS algorithm...
    while (l <= h)
    {

        int mid = l + (h - l) / 2; // possible value of time taken.

        // this checks if all chefs can make the needed cookies in mid amount of time ?
        if (isJobFinished(rank, m, mid))
        {
            // if yes, then go to left side.
            ans = mid;
            h = mid - 1;
        }
        else
        {
            // if no, then go to right side.
            l = mid + 1;
        }
    }
    return ans;
}

// WorkOut and logic:
/*
Cookies and Cooks

R -> 1 to 10

Cook with 2R rating means

Ist dish --> 2 mins
IInd dish --> 4 mins   Total 12 mins for 3 dishes.
IIrd Dish --> 6 mins

Logic: R(1+2+3+...no.of dishes) --> Total time Taken

To Find: To complete an Orader of M dishes, given ratings of cooks, To Find min time required to complete this order.


Ranks:             Asked to minimise the time taken to bake all cookies

1 2 3 4

Total Cookies want: 11

MAx possible value of R is 10 and no.of cookies is 11.
Max time for cook 1R Cook is 10(11*12/2) --> 660 min (worst case)

Range for time taken: 0 to 660

0 1 2 3 4 ........................330............................ 660
l                                  m                               h

time taken by cook: R(n*n+1/2) where n is no of dish

IF,
Total Possible time taken: 20 min (for example mid)

cook1: 1(1+2+3+4+5) = 15 mins < 20 -> 5 cookies

cook2: 2(1+2+3+4) = 20 --> 4 cookies

cook3: 3(1+2+3) = 18 < 20   --> 3 cookies

cook4: 4(1+2) = 12 < 20 --> 2cookies


So Total Cookies is 5+4+3+2 -> 14 cookies in 20 mins by all the cooks together.

then if in 20 mins they can together make 14 cookies, we should see go left to look in lower time region in the solution space.
i.e h=mid-1;

OR

If they are not able to then go Right side of the solution space to look for the solution.
i,e l=mid+1;



Possible mids and status:

mid = 20 (possible) 14 cookies then ovio more than 20 more than 14 possible.
        Target cookie is 11 so we go left in the sample space.

*/