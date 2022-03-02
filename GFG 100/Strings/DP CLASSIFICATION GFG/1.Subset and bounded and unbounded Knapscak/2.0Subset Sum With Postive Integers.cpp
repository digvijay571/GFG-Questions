// Questions with target sum and positive intergers:
//  Q.Subset sum
//  Q.Count of subsets sum with a given sum

// variation
// Q.Equal sum partition
// Q.Partion into k equal subsets

// Q.Count the number of subset with a given difference:
// https://leetcode.com/discuss/interview-question/1271034/count-no-of-subsets-with-given-difference-dp
// Let sum of subset 1 be s1 and subset 2 with s2
// s1 - s2 = diff (given)
// s1 + s2=sum of array (logical)
// Therefore adding both eq we get :
// 2s1= diff + sum of array
// s1= (diff + sum of array)/2;
// Problem reduces to find no of subsets with given sum**

// Without target subset sum:we find calculatedSum at last level

// Q.Minimum subset sum difference

// Subset Sum:https://techiedelight.com/practice/?problem=SubsetSumProblem

// Key point is base condition
// Because there are only positive elements
// So if we find target then we cannot form target by using more elements as it is going to increase the sums
// Follow ups:What if elements are non - negative
//  :What if elements are intergers
// Can u find subset or subsets in above?
class Solution
{
public:
    bool isSubsetSum(int n, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 1;
        if (n == 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];
        int take = 0;
        if (nums[n - 1] <= target)
            take = isSubsetSum(n - 1, target - nums[n - 1], nums, dp);

        return dp[n][target] = take || isSubsetSum(n - 1, target, nums, dp);
    }
    bool subsetSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return isSubsetSum(nums.size(), target, nums, dp);
    }
};

// Equal Sum Partition:https://leetcode.com/problems/partition-equal-subset-sum/

class Solution
{
public:
    bool subsetSum(int n, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 1;

        if (n == 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int take = 0;

        if (nums[n - 1] <= target)
            take = subsetSum(n - 1, target - nums[n - 1], nums, dp);

        return dp[n][target] = take || subsetSum(n - 1, target, nums, dp);
    }

    // key: only positive integers: so i can use subset sum with sum= totalSum/2;
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
        if (!(sum & 1)) // sum is even
        {
            // Equal partition can be possible
            return subsetSum(n, sum / 2, nums, dp);
        }
        return 0;
    }
};

// if there are positive elements count subsets which have sum equal to k

int subsetCount(int *A, int N, int target)
{

    if (target == 0)
    {
        return 1;
    }

    if (N == 0)
    {
        return 0;
    }

    /*
                             i (element of the array)
                (include i) / \ (not include i)
        ('A' no. of subsets) A   B ('B' no. of subsets)
    */
    if (A[N - 1] <= target)
    {

        return subsetCount(A, N - 1, target) + subsetCount(A, N - 1, target - A[N - 1]);
    }

    return subsetCount(A, N - 1, target);
}

// Minimum subset sum difference
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
//  integer array arr
// TO find all possible values of subset sum1 ,and minimize diff

int findMinRec(int arr[], int i, int sumCalculated,
               int sumTotal, vector<vector<int>> &dp)
{
    // If we have reached last element.  Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated.  Return absolute difference
    // of two sums.
    if (i == 0)
        return abs((sumTotal - sumCalculated) - sumCalculated);

    if (dp[i][sumCalculated] != -1)
        return dp[i][sumCalculated];
    // For every item arr[i], we have two choices
    // (1) We do not include it first set
    // (2) We include it in first set
    // We return minimum of two choices
    return dp[i][sumCalculated] = min(
               findMinRec(arr, i - 1, sumCalculated + arr[i - 1],
                          sumTotal, dp),
               findMinRec(arr, i - 1, sumCalculated, sumTotal, dp));
}

// Returns minimum possible difference between sums
// of two subsets
int findMin(int arr[], int n)
{
    // Compute total sum of elements

    int sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(sumTotal + 1, -1));
    // Compute result using recursive function
    return findMinRec(arr, n, 0, sumTotal, dp);
}

public:
int minDifference(int arr[], int n)
{
    return findMin(arr, n);
}
}
;

// Target Sum:https://leetcode.com/problems/target-sum/
// key: ans is calculated at last level
