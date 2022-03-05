// can  House Robber be solved like this?

// https://leetcode.com/problems/student-attendance-record-ii/
const int mx = 1e5 + 123;
const int MOD = 1e9 + 7;
int dp[mx][3][4], n;

int solve(int i, int absent_stock, int late_stock)
{
    if (i == n)
        return 1;
    if (dp[i][absent_stock][late_stock] != -1)
        return dp[i][absent_stock][late_stock];

    long long ret = solve(i + 1, absent_stock, 2); // P
    ret %= MOD;

    if (absent_stock >= 1)
    {
        ret += solve(i + 1, absent_stock - 1, 2);
        ret %= MOD;
    }
    if (late_stock >= 1)
    {
        ret += solve(i + 1, absent_stock, late_stock - 1);
        ret %= MOD;
    }

    return dp[i][absent_stock][late_stock] = ret;
}

class Solution
{
public:
    int checkRecord(int val)
    {
        n = val;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 2);
    }
};

// Total Strings
// Stock based choices
const int MOD = 1000000007;

int count(int n, int b, int c, vector<vector<vector<int>>> &dp)
{

    if (n == 0)
        return 1;
    // take b
    if (dp[n][b][c] != -1)
        return dp[n][b][c];
    int take_b = 0, take_c = 0;

    if (b >= 1) // if there is stock of b
        take_b = count(n - 1, b - 1, c, dp) % MOD;
    // take c
    if (c >= 1) // if there is stock of c
        take_c = count(n - 1, b, c - 1, dp) % MOD;

    // take a
    int take_a = count(n - 1, b, c, dp) % MOD;

    return dp[n][b][c] = (take_a + take_b + take_c) % MOD;
}
