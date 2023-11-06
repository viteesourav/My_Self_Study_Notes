// Link: https://leetcode.com/problems/minimum-cost-for-tickets/
/*
So You planned to Travel the World For a whole year. Given a array of Days which ideal for you to traval and cost of Passes.
    Find the mini Possible cost For traveling.
    eg: days -> [1, 3, 4, 5, 7, 8, 10] -> this are the days you want to travel.
        cost -> [2, 7, 15] -> cost[0] i.e 1 day pass, cost[1] i.e 7 days pass, cost[2] i.e 30 days pass.

    -- With each pass, You have some period, in which you can travel Freely.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Appraoch1: Recursive Choice Approach.
    int solve1(int n, vector<int> &days, vector<int> &costs, int dayIndex)
    {
        // baesCase: If we already completed n days journey i.e if day index goes out of bound from days array
        if (dayIndex >= n)
        {
            return 0;
        }

        // If we at a particular day, 3 choices we have...
        // 1.you have a daily pass...
        int opt1 = costs[0] + solve1(n, days, costs, dayIndex + 1); // Recursion will fetch the sol from next day

        // 2.If you have weekly pass...
        // need to move to day after a week form curr dayIndex..
        int currDay = dayIndex;
        while (currDay < n && days[currDay] < days[dayIndex] + 7)
        {
            currDay++;
        }
        int opt2 = costs[1] + solve1(n, days, costs, currDay);

        // 2.If you have montly pass...
        // need to move to day after a month form curr dayIndex..
        currDay = dayIndex;
        while (currDay < n && days[currDay] < days[dayIndex] + 30)
        {
            currDay++;
        }
        int opt3 = costs[2] + solve1(n, days, costs, currDay);

        // Now we have the cost from all 3 options, we need to choose the min...
        return min(opt1, min(opt2, opt3));
    }

    // Appraoch2: Recursion + Memorization Method
    int solve2(int n, vector<int> &days, vector<int> &costs, int dayIndex, vector<int> &dp)
    {
        // baesCase: If we already completed n days journey i.e if day index goes out of bound from days array
        if (dayIndex >= n)
        {
            return 0;
        }

        // Check if dp already holds the ans for dayIndex...
        if (dp[dayIndex] != -1)
            return dp[dayIndex];

        // If we at a particular day, 3 choices we have...
        // 1.you have a daily pass...
        int opt1 = costs[0] + solve2(n, days, costs, dayIndex + 1, dp); // Recursion will fetch the sol from next day

        // 2.If you have weekly pass...
        // need to move to day after a week form curr dayIndex..
        int currDay = dayIndex;
        while (currDay < n && days[currDay] < days[dayIndex] + 7)
        {
            currDay++;
        }
        int opt2 = costs[1] + solve2(n, days, costs, currDay, dp);

        // 2.If you have montly pass...
        // need to move to day after a month form curr dayIndex..
        currDay = dayIndex;
        while (currDay < n && days[currDay] < days[dayIndex] + 30)
        {
            currDay++;
        }
        int opt3 = costs[2] + solve2(n, days, costs, currDay, dp);

        // Now we have the cost from all 3 options, we need to choose the min...
        dp[dayIndex] = min(opt1, min(opt2, opt3));

        return dp[dayIndex];
    }

    // Approach3: Tabulation Method [Bottom-up Approach]
    int solve3(int n, vector<int> &days, vector<int> &costs)
    {
        // 1. First lets create the dp vector..
        vector<int> dp(n + 1, INT_MAX); // since we need to find the min Cost..

        // 2.Analysing the base case and initializing the dp vector..
        dp[n] = 0;

        // Now For calculating min Cost for other days, lets use a loop. [right to left]
        // Reason: As per base case of dp, we know dp[n], using this we need to find dp[n-1] to dp[0]
        for (int index = n - 1; index >= 0; index--)
        {

            // If we at a particular day, 3 choices we have...
            // 1.you have a daily pass...
            int opt1 = costs[0] + dp[index + 1];

            // 2.If you have weekly pass...
            // need to move to day after a week form curr dayIndex..
            int currDay = index;
            while (currDay < n && days[currDay] < days[index] + 7)
            {
                currDay++;
            }
            int opt2 = costs[1] + dp[currDay];

            // 2.If you have montly pass...
            // need to move to day after a month form curr dayIndex..
            currDay = index;
            while (currDay < n && days[currDay] < days[index] + 30)
            {
                currDay++;
            }
            int opt3 = costs[2] + dp[currDay];

            // Now we have the cost from all 3 options, we need to choose the min...
            dp[index] = min(opt1, min(opt2, opt3));
        }
        return dp[0]; // as On 0th day our journey ends.
    }

    // Appraoch4: Space Optimized Method [using Queues to Keep Track of Days in Weekly and monthly pass]
    int solve4(int n, vector<int> &days, vector<int> &costs)
    {
        // Lets have Queues of weekly and montly of format: pair<day, cost till that day>
        queue<pair<int, int>> weekly, montly; // SC: O(1) as we know at max this queue will hold 365 elements..

        int ans = 0;

        // we will iterate days..
        for (int day : days)
        {
            // 1. First Remove Expired days from the Queues if they are not empty..
            while (!weekly.empty() && weekly.front().first <= day - 7)
            { // weekly.front() -> gives the {day, cost pair in the front of Queue}
                weekly.pop();
            }
            while (!montly.empty() && montly.front().first <= day - 30)
            { // if the front day is out the 30 days range for day, remove it.
                montly.pop();
            }

            // 2.Push the new day and cost in the Queue...
            weekly.push(make_pair(day, ans + costs[1]));
            montly.push(make_pair(day, ans + costs[2]));

            // 3. Compare the costs for daily, weekly and montly and update ans..
            ans = min(ans + costs[0], min(weekly.front().second, montly.front().second)); // weekly.front() -> give a pair {day, cost till that day}
        }
        return ans;
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size(); // total number of days for journey.
        int dayIndex = 0;    // starting days at index 0.

        // return solve1(n, days, costs, dayIndex);

        // vector<int> dp(n+1, -1);
        // return solve2(n, days, costs, dayIndex, dp);

        // return solve3(n, days, costs);

        return solve4(n, days, costs);
    }
};

/*
LogiC:
Recursive logic:
    -- So You are standing on a particular day. You got 3 options.
       1) You buy day pass -> cost[0] and allows you travel on that day.
       2) You buy weekly pass -> cost[1] and allows you to travel from that day till next 7 days.
       3) You buy Montly pass -> cost[2] and allows you to travel from that day till next 30 days.
    -- Recursion will find the solution for all this and then record the mini Cost in ans.
NOTE:
    --> While solving for option 2 and 3, Make sure, You move the currDay pointer to day after 7 days and 30 days respectively.
    --> BaseCASE:
        - If you are already reached the last day of travel. What is the cost ? it will be 0 since You completed your journey.

Space Optimized Appraoch: [using Queue to keep Track of weekly and montly pass]
    Steps:
        1) First you initialize the ans with 0.
           -- craete 2 Queues of type: pair<day, cost till that day> to hold weekly and montly.
        2) Loop in the days array.
            1) First remove all expire days present in the queue.
                -- If queue is not empty and front day <= currDay - 7 [for weekly], You pop the front.
            2) Now For each day,
                -- push a pair in the weekly and montly Queue with currday and fair will be ans + cost[1] [for weekly]
            3) Now update the ans with min of the weekly, montly and daily cost for each days..
                -- dailyCost -> ans + cost[0]
                -- montlyCost -> montly.front().second [holds the cost]
                -- weeklyCost -> weekly.front().second [holds the cost]
        -- ans will return the min Cost required for completing the journey.
*/