// Link: https://www.codingninjas.com/studio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTab=0
/*
[hard]
You have an array[elemts can be positive or neagtive] and you have window k.
    Need to return the total Sum of all min and max elements present in each k group.
*/

#define ll long long
#include <bits/stdc++.h>
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{

    // Appraoch: using 2 dequeue, one stores max and min ele index at front in group of k elements...
    // TC: O(n) SC: O(k)
    ll ans = 0;
    deque<int> maxi(k), mini(k);

    // lets prcoess the first k window...
    for (int i = 0; i < k; i++)
    {
        // Aim is the put index's in dequeues such that,
        // front gives the max ele from maxi, and min from mini deque..
        while (!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();
        while (!mini.empty() && nums[mini.back()] >= nums[i])
            mini.pop_back();

        // after you removed.. push the current val..
        maxi.push_back(i);
        mini.push_back(i);
    }

    // update the ans...
    ans += nums[maxi.front()] + nums[mini.front()];

    // now process rest of the k groups...
    for (int i = k; i < n; i++)
    {

        // check if the windows changes.. handle removal from maxi and mini...
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        // Now handle the addition of the ith element...[copy from above]
        while (!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();
        while (!mini.empty() && nums[mini.back()] >= nums[i])
            mini.pop_back();

        // after you removed.. push the current val..
        maxi.push_back(i);
        mini.push_back(i);

        // update the ans...
        ans += nums[maxi.front()] + nums[mini.front()];
    }
    return ans;
}

/*
 TC: O(n) SC: O(k)
 Appraoch: Using deque, to track the min and max ele index from each window...
    -- First we need 2 deque, maxi and mini. [size can be k]
    -- Ans to return.
    Solving for the first kth Group.
        -- we have to push the index in maxi and mini in such a way that,
            maxi.front() -> max element index in the kth window
            mini.front() -> mini element index in the kth window
        -- In maxi Queue, Pop from back till the incoming element is greater, then push it.
        -- In mini Queue, Pop from back till the incoming element is smaller, then push it.
    Thus, the front of both the queue, will hold, max and mini element index resp.

   -- Update ans for the first k group of elements..

   -- For the next k group of element, Run a loop [For each incoming element]
      -- Check if the front of both the queues, went out of bound ?
         if yes, Pop them from front.
      -- Now removal is done, Do the above logic, update the maxi and mini queue for the ith element  [same logic as we used in 1st K group]
      -- update the ans.
    return ans. [***DONE***]
*/