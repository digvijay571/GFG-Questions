// HOUSE ROBBER
//  https://leetcode.com/problems/house-robber/
// Maximum sum such that no two elements are adjacent
class Solution
{
public:
    // Starting from end:
    // Two choices:notPick , pick_notPick
    //  int notPick = money(n-1,nums);
    //  int pick_notPick = nums[n-1]+money(n-2,nums);

    // Recurrence:
    //  dp[0]=0,dp[1]=nums[0]
    //  dp[i]= max(dp[i-1], nums[i-1]+dp[i-2]);i>=2

    // Recursive solution
    int money(int n, vector<int> &nums)
    {
        if (n <= 0)
            return 0;

        int notPick = money(n - 1, nums);
        int pick_notPick = nums[n - 1] + money(n - 2, nums);

        return max(notPick, pick_notPick);
    }

    int rob(vector<int> &nums)
    {
        // conversion to Tabulation:Replace above recurrnce n with i->intermediate state and start solving from base case

        int n = nums.size();

        vector<int> dp(n + 1, 0);

        dp[0] = 0; // if(i<=0) return 0;

        if (n >= 1)
            dp[1] = nums[0]; // dp[1]=max(dp[i-1], nums[i-1]+dp[i-2])=max(dp[0],nums[0]+0) = max(0,nums[0]) = nums[0]

        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);

        return dp[n];
    }
};

// Variation:
//  We need to pick a subset of the coins to maximize their sum, with a constraint that we can not pick 3 consecutive coins together.
// Maximum subsequence sum such that no three are consecutive

int maxCoins(vector<int> &coins, int n)
{
    if (n <= 0)
        return 0;

    int skip = maxCoins(coins, n - 1);
    int pickskip = coins[n - 1] + maxCoins(coins, n - 2);
    int pickpickSkip = coins[n - 1] + coins[n - 2] + maxcoins(coins, n - 3);

    return max(max(skip, pickskip), pickpick);
}

// We have a set of coins in a row, all with positive values. We need to pick a subset of the coins to maximize their sum, with a constraint that we can not pick K consecutive coins together.
// https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-k-elements-are-consecutive/

// https://www.geeksforgeeks.org/find-minimum-sum-one-every-three-consecutive-elements-taken/
// Let sum(i) be the minimum possible sum when arr[i] is part of a solution sum (not necessarily result) and is last picked element.
// Then our result is minimum of sum(n-1), sum(n-2) and sum(n-3) [We must pick at least one of the last three elements].
