// Link: https://www.codingninjas.com/studio/problems/find-the-first-circular-tour-that-visits-all-the-petrol-pumps_799923
//         https://leetcode.com/problems/gas-station/
/*
Basically, You have n petrol pumps in a circle. You given what is petrol available at each pump and how much distance you can travel.
    Now, Find out the starting point so that you will be able to complete a complete circle.
*/

#include <bits/stdc++.h>
using namespace std;

int firstCircularTour(vector<int> &petrol, vector<int> &distance, int N)
{
    // Appraoch: we will solve using defficent and balance petrol method...
    long long defficentPetrol = 0; // This will store the petrol needed, if journey breaks in mid.
    long long balancePetrol = 0;   // This stores the balance petrol, after each Journey..
    int start = 0;                 // mark the start index of truck.
    // iterate over all pumps one by one...
    for (int i = 0; i < N; i++)
    {
        balancePetrol += petrol[i] - distance[i];

        // check if we can reach the next pump ?
        if (balancePetrol < 0)
        {
            // If journey breaks in middle...
            defficentPetrol += balancePetrol; // update the additonal Fuel needed.
            start = i + 1;                    // update truch starting point.
            balancePetrol = 0;                // reset the balance petrol.
        }
    }

    // Now we completed the loop...
    // check if the circle can be completed or not ?
    if (defficentPetrol + balancePetrol >= 0)
    {
        return start; // we can complete one circle from start...
    }
    else
    {
        return -1; // No possible solution exist.
    }
}

/*
example:

petrol: 4 6 7 4 ,  Distance: 6 5 3 5

lets assume pairs of (petrol available (p), dist can be covered(d)) for each understanding..
  0     1      2     3
(4,6) (6, 5) (7,3) (4,5)

Appraoch 1: Assume it a Cyclic Queue and solve the problem.
    -- Have one variable balance to store the balance amount of petrol left after each journey.
    -- Start front and rear both at 0th index.
    -- Run a loop till front == rear
        if p+balance-d >= 0, means you can reach the next pump, store the balance petrol and rear++.
        if not, means if you start from front index, you cannot complete cycle.
            -- update balance petrol = 0. [we are checking journey again]
            -- update front = rear+1 i.e move front the next rear location [**Important condi**]
    -- If rear comes back to front by the above condition, Front index [ans]
    -- If all pump visited and for all of them rear not reaching front, return -1 [cycle not possible]

Problem with above Approach:
    -- If a Journey breaks, we are updating front to next of rear. But inorder to check the cycle,
        rear needs to come all the way to front again. [Nodes are visited 2 times]

Appraoch 2: Efficeint and preffred appraoch.
    Store the deficient Petrol needed [If the journey breaks] [Just 1 loop is enough]
    -- Declare deficient Petrol = 0 [If journey breaks, How much petrol extra we need ?]
    -- decalre balance petrol = 0 [In each joueney what is additional ]
    -- start points to index 0.
    -- Start a loop from 0 to nth index.
        -- If p+balace-d >= 0, then just store the balance petrol and move on.
        -- If journey breaks,
            -- start points to next ith index.
            -- update the deficient petrol as p+balance-d.
            -- restart balance as 0.
    -- Now once you reach the end of the loop,
        check if balance + deficeint >= 0 ? [**Important condition**]
        If yes, You can complete the circle
        If no, Circle is not possible. [retrun -1]
*/