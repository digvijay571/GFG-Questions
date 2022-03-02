
// Palindrome reads same backwards

// palindromic check
// if(s[i] == s[j])
// {

// }

//   -->  <--
//   abcddcba
//   i      j


// single char is a palindrome
   

// if we mirror a string it becomes palindrome
// if we mirror a palindrome it is still a palindrome

// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
public:
    bool isPalindrome(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 1;

        if (s[i] != s[j])
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = isPalindrome(i + 1, j - 1, s, dp);
        // returns bool
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        int len = 1;
        int start = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s, dp))
                {
                    if (j - i + 1 > len)
                    {
                        len = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, len);
    }
};