// Distinct SUbsequnces
// https://leetcode.com/problems/distinct-subsequences/

// Two things given:
// they can be same
// else
// they will be diffrent

// when the charaters are equal:
// we can either move from it ..., or take it for current subsequnce

// not equal
// move move from it

class Solution
{
public:
    int count(int n1, int n2, string &s, string &t, vector<vector<int>> &dp)
    {
        //   1234567
        //  "rabbbit"
        //  "rabbit"
        if (!n1 && n2)
            return 0;
        if (!n2)
            return 1;

        if (dp[n1][n2] != -1)
            return dp[n1][n2];

        if (s[n1 - 1] == t[n2 - 1])
        {
            return dp[n1][n2] = count(n1 - 1, n2 - 1, s, t, dp) + count(n1 - 1, n2, s, t, dp);
        }
        return dp[n1][n2] = count(n1 - 1, n2, s, t, dp);
    }
    int numDistinct(string s, string t)
    {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return count(n1, n2, s, t, dp);
    }
};



//Count distinct Palindromic Subsequces