
class Solution
{
public:
    vector<vector<int>> dp;

    bool isPalindrome(int l, int r, string &s)
    {
        if (l >= r)
            return 1;

        if (s[l] != s[r])
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        return dp[l][r] = isPalindrome(l + 1, r - 1, s);
    }

    vector<vector<string>> ans;

    void solve(int start, string s, vector<string> &partition)
    {
        if (start == s.size())
        {
            ans.push_back(partition);
            return;
        }

        for (int end = start; end < s.size(); end++)
        {
            if (isPalindrome(start, end, s))
            {
                partition.push_back(s.substr(start, end - start + 1));
                solve(end + 1, s, partition);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {

        int n = s.size();
        dp.resize(n, vector<int>(n, -1));

        vector<string> partition;
        solve(0, s, partition);

        return ans;
    }
};

// fixed K-partions to Do
//  https://leetcode.com/problems/largest-sum-of-averages/
class Solution
{
public:
    // for the last partition
    double avg(int start, vector<int> &A)
    {
        int end = A.size() - 1;
        double sum = 0;
        for (int i = start; i <= end; i++)
            sum += A[i];
        return sum / (end - start + 1);
    }

    // i->start
    // j->end
    double solve(int i, vector<int> &nums, int K, vector<vector<double>> &memo)
    {

        if (i >= nums.size())
            return 0; // do i reahed end?

        if (K == 1)
            return avg(i, nums); // done k-1 partions..

        if (memo[i][K] != -1)
            return memo[i][K];

        double sum = 0; // used for finding avg of current partition

        int max_group_size = nums.size() - K; // max elements in the group for the given K

        //
        for (int j = i; j <= max_group_size; j++)
        {
            sum += nums[j];
            // contribution of avg sum for current partion + recusively calling to get minimum avg sum for remaining partions
            memo[i][K] = max(memo[i][K], sum / (j - i + 1) + solve(j + 1, nums, K - 1, memo));
        }
        return memo[i][K];
    }

    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<double>> dp(n, vector<double>(k + 1, -1));
        return solve(0, nums, k, dp);
    }
};


// https://leetcode.com/problems/partition-array-for-maximum-sum/
// Partion with  Length at most k

class Solution
{
public:
    // length at most k
    int solve(int start, vector<int> &nums, int k, vector<vector<int>> &dp)
    {

        int n = nums.size();

        if (start >= n)
            return 0;

        if (dp[start][k] != -1)
            return dp[start][k];

        int sum = 0;
        int currmax = 0;
        for (int end = start; end < min(start + k, n); end++)
        {
            currmax = max(currmax, nums[end]);
                 // contribution of sum for current partion +Recursively calling for other partions
            sum = max(sum, currmax * (end - start + 1) + solve(end + 1, nums, k, dp));
        }
        return dp[start][k] = sum;
    }

    int maxSumAfterPartitioning(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(0, nums, k, dp);
    }
};

// https://leetcode.com/problems/partition-array-for-maximum-sum/