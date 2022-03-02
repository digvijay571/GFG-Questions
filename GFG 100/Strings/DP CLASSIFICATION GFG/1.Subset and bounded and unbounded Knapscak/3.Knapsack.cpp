// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
    // either pick the complete item or dont pick it (0-1 property).
    // maximum value subset of val[]
    // such that sum of the weights of this subset is smaller than or equal to W.
    // as sum can be less or equal to W so, no target condition

public:
    int knap(int n, int cap, int wt[], int val[], vector<vector<int>> &dp)
    {

        if (n == 0)
            return 0; // sum is zero if n is zero

        if (dp[n][cap] != -1)
            return dp[n][cap];

        // take
        int take = 0;
        if (wt[n - 1] <= cap) // boundary check
        {
            // contribution+call()
            take = val[n - 1] + knap(n - 1, cap - wt[n - 1], wt, val, dp);
        }

        int not_take = knap(n - 1, cap, wt, val, dp);

        return dp[n][cap] = max(take, not_take);
    }

    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return knap(n, W, wt, val, dp);
    }
};
