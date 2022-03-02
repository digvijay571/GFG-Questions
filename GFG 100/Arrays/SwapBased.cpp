//Adjacent Swap Based Questions
//Swaping Adajacent is similar to shifiting all elements toward the element and then place it at final position

//Q.To find minimum swaps to
// sort an array of 0s and 1s.
int findMinSwaps(int arr[], int n)
{
    // Array to store count of zeroes
    int noOfZeroes[n];
    memset(noOfZeroes, 0, sizeof(noOfZeroes));

    int i, count = 0;

    // Count number of zeroes
    // on right side of every one.
    noOfZeroes[n - 1] = 1 - arr[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        noOfZeroes[i] = noOfZeroes[i + 1];
        if (arr[i] == 0)
            noOfZeroes[i]++;
    }

    // Count total number of swaps by adding number
    // of zeroes on right side of every one.
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            count += noOfZeroes[i];
    }

    return count;
}

//GIVEN 2*N elements , bring all the same elements together

int findMinimumAdjacentSwaps(int arr[], int N)
{
    // visited array to check if value is seen already
    bool visited[N + 1];

    int minimumSwaps = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < 2 * N; i++)
    {

        // If the arr[i] is seen first time
        if (visited[arr[i]] == false)
        {
            visited[arr[i]] = true;

            // stores the number of swaps required to
            // find the correct position of current
            // element's partner
            int count = 0;

            for (int j = i + 1; j < 2 * N; j++)
            {

                // Increment count only if the current
                // element has not been visited yet (if is
                // visited, means it has already been placed
                // at its correct position)
                if (visited[arr[j]] == false)
                    count++;

                // If current element's partner is found
                else if (arr[i] == arr[j])
                    minimumSwaps += count;
            }
        }
    }
    return minimumSwaps;
}

// minimum-swaps-required-group-1s-together:Sliding Window
//Idea is to slide window of no. of 1s ....and return TotalOnes - maxOnesinthatWindow;
#include <bits/stdc++.h>

using namespace std;

int minSwaps(int arr[], int n)
{
    int totalCount = 0; // To store total number of ones
    // count total no of ones
    for (int i = 0; i < n; i++)
        totalCount += arr[i];

    int currCount = 0; // To store count of ones in current window
    int maxCount = 0;  // To store maximum count ones out of all windows
    int i = 0;         // start of window
    int j = 0;         // end of window

    while (j < n)
    {
        currCount += arr[j];

        // update maxCount when reach window size i.e. total count of ones in array
        if ((j - i + 1) == totalCount)
        {
            maxCount = max(maxCount, currCount);
            if (arr[i] == 1)
                currCount--; // decrease current count if first element of window is 1
            i++;             // slide window
        }
        j++;
    }

    return totalCount - maxCount; // return total no of ones in array - maximum count of ones out of all windows
}

//Q.minimum-adjacent-swaps-for-k-consecutive-ones
// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/discuss/1722413/Minimum-swaps-and-K-together-or-C%2B%2B-or-O(n)

//Given an array arr of n positive integers and a number k.
// One can apply a swap operation on the array any number of times,
//  i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] .
//  Find the minimum number of swaps required to bring all the numbers less than or equal to k together,
//  i.e. make them a contiguous subarray.

int minSwap(int arr[], int n, int k)
{
    // Complet the function
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            count++;
    }
    int bad = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > k)
            bad++;
    }

    int ans = bad;
    for (int i = 0, j = count; j < n; i++, j++)
    {
        if (arr[j] > k)
            bad++;

        if (arr[i] > k)
            bad--;

        ans = min(ans, bad);
    }

    return ans;
}

// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/

//Variation is to bring all persons together if they are seated randomly

//Duplicate Nos. 1
int findDuplicate(vector<int> &nums)
{
    int slow = 0;
    int fast = 0;

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = 0;
    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }

    return fast;
}
//All Duplicate nos.
vector<int> findDuplicates(vector<int> &nums)
{

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
            ans.push_back(nums[i]);
    }
    return ans;
}
//First missing positive
//Idea is to place elements at correct postion i.e nums[i] = i+1 ...it gives nums[i]-1 =i .... nums[nums[i]-1]=nums[i]
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while ((nums[i] >= 1 && nums[i] <= n) && nums[i] != nums[nums[i] - 1])
            swap(nums[nums[i] - 1], nums[i]);
    }
    int count = 1;
    for (auto num : nums)
    {
        if (num == count)
            count++;
        else
            break;
    }
    return count;
}