

// LIS -Longest Increasing Subsequnce-SUM - contribution of element values

// NInja at Jym

int maxIncreasingDumbbellsSum(vector<int> &nums, int n)
{
    // dp[i] denotes length with rack[i]

    vector<int> dp(n, 0);

    int LIS = 1; // for calculating the maximum sum

    for (int i = 0; i < n; i++) // one loop is for calculating dp[i]
    {
        dp[i] = 1;                  // dp[i]=1;initialization because len will be mimimum 1 (it will definetly include nums[i]) (...nums[i])
        for (int j = 0; j < i; j++) // calculating current problem dp[i]
                                    // using subproblem dp[j]:dp[0]...dp[i-1]
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        LIS = max(LIS, dp[i]); // maximizing ans
    }
    return ans;
}

// Maximum IncreasingSubsequnce -SUM - contribution of element values

// NInja at Jym

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // dp[i] denotes maximumSumOfIncresingSubsequenceSumEnding with rack[i]

    vector<int> dp(n, 0);

    int LIS = 1; // for calculating the maximum sum

    for (int i = 0; i < n; i++) // one loop is for calculating dp[i]
    {
        dp[i] = rack[i];            // dp[i]=1;initialization as
        for (int j = 0; j < i; j++) // calculating current problem dp[i]
                                    // using subproblem dp[j]:dp[0]...dp[i-1]
        {
            if (rack[i] > rack[j]) // can current element rack[i] can be attached
                                   // after the subsequnce ending at j
                                   // as the subsequece is increasing so
                                   // rack[i]>rack[j]
            {
                dp[i] = max(dp[i], rack[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]); // maximizing ans
    }
    return ans;
}

// LIS -SUM

// NInja at Jym

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // dp[i] denotes maximumORLargestIncresingSubsequenceSumEnding with rack[i]
    vector<int> dp(n, 0);

    int LIS = 1; // for calculating the maximum sum

    for (int i = 0; i < n; i++) // one loop is for calculating dp[i]
    {
        dp[i] = rack[i];            // dp[i]=1;initialization as
        for (int j = 0; j < i; j++) // calculating current problem dp[i]
                                    // using subproblem dp[j]:dp[0]...dp[i-1]
        {
            if (rack[i] > rack[j]) // can current element rack[i] can be attached
                                   // after the subsequnce ending at j
                                   // as the subsequece is increasing so
                                   // rack[i]>rack[j]
            {
                dp[i] = max(dp[i], rack[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]); // maximizing ans
    }
    return ans;
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // dp[i] denotes maximumORLargestIncresingSubsequenceSumEndingAti
    vector<int> dp(n, 0);

    int ans = rack[0]; // for calculating the maximum sum

    for (int i = 0; i < n; i++) // one loop is for calculating dp[i]
    {
        dp[i] = rack[i];            // dp[i]=1;initialization as
        for (int j = 0; j < i; j++) // calculating current problem dp[i]
                                    // using subproblem dp[j]:dp[0]...dp[i-1]
        {
            if (rack[i] > rack[j]) // can current element rack[i] can be attached
                                   // after the subsequnce ending at j
                                   // as the subsequece is increasing so
                                   // rack[i]>rack[j]
            {
                dp[i] = max(dp[i], rack[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]); // maximizing ans
    }
    return ans;
}

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        // * Here we had to count the LIS. So we maintained another array named count.
        // * The idea is to use two arrays dp[n] and cnt[n] to record the maximum length of Increasing Subsequence and the
        // * coresponding number of these sequence which ends with nums[i], respectively. That is:
        // *
        // * dp[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
        // *
        // * cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].
        // *
        // * Then, the result is the sum of each cnt[i] while its corresponding len[i] is the maximum length.

        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int LIS = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] < dp[j] + 1) // dp[j]+1 is greater means dp[i] should be updated to dp[j]+1 -reset count- same as max(dp[i],dp[j]+1)
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // count will be same as count[j] as we are just appending extra nums[i]
                    }
                    else if (dp[i] == dp[j] + 1) // equal then we have to increase the count
                    {
                        count[i] += count[j]; // count[i] +=count[j]
                    }
                }
            }
            LIS = max(LIS, dp[i]);
        }

        int c = 0; // count of LIS
        for (int i = 0; i < n; i++)
        {
            if (LIS == dp[i])
                c += count[i];
        }
        return c;
    }
};

// Longest Common Increasing Subsequence of two arrays

// Find LCS

// Find then LIS