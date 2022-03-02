

// 2 strings and Subseqence

// LCS:Longest Common Subequence
// Print LCS

// Longest common substring
// Print

// Shortest Common Superseqence
// m+n-LCS(m,n)
// common remove kardo using LCS

// Longest PalindromicSubseqence
////longestPalindromicSubsequnce=LCS(s,srev)

// Insertion/Deletion PalindromicSubseqence
////longestPalindromicSubsequnce=n-LCS(s,srev)

// LCS
// dp[n1+1][n2+1]
// base case if any of string is empty dp[i][j]=0 //fist row and col =0
// if same
// then dp[i][j] = 1+dp[i-1][j-1]<-digonal
// else
// dp[i][j]=max(dp[i-1][j],dp[i][j-1]) <-max(up,left)

// Our ans is at dp[n1][n2]
// Printing LCS
// int i=n1,j=n2
// take two pointers
// LCS=""
//(i>0&&j>0)//none of them is empty
//  {
//  if(s1[i-1]==s2[j-1])
//  LCS.push_back(s1[n1-1])
// 	i--,j--;//move digonally back
// else
// {
// 	//move towards the greater
// 	if(dp[i-1][j]>dp[i][j-1])
// 	{
// 		i--;//move up
// 	}
// 	else
// 	{
// 		j--;//move left
// 	}
// }
// }

// https://leetcode.com/problems/longest-common-subsequence/discuss/1330473/C%2B%2B-or-Length-of-LCS-or-Print-LCS-or-T.C-O(n*m)-or-Tabulation
// https://leetcode.com/problems/longest-common-subsequence/discuss/1739337/Print-LCS-Interview-question-(instead-of-returning-Longest-length)
// https://leetcode.com/problems/shortest-common-supersequence/discuss/1807266/C%2B%2B-or-DP-or-using-LCS-or-Easy

// Longest common substring-

// int maxLen=0;
//  for (int i = 0; i <= m; i++) {
//         for (int j = 0; j <= n; j++) {
//             if (i == 0 || j == 0)
//                 LCSuff[i][j] = 0;

//             else if (X[i - 1] == Y[j - 1]) {
//                 LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
//                 if (maxLen < LCSuff[i][j]) {
//                     maxLen = LCSuff[i][j];
//                     Endindex=i;
//                 }
//             }
//             else
//                 LCSuff[i][j] = 0;
//         }
//     }
// 	return X.substr(Endindex-maxLen,maxLen);

// Shortest Common Superseqence
// m+n-LCS(m,n)
// common remove kardo using LCS

// Longest PalindromicSubseqence
////longestPalindromicSubsequnce=LCS(s,srev)

// Insertion/Deletion PalindromicSubseqence
////longestPalindromicSubsequnce=n-LCS(s,srev)

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution
{
public:
    int minInsertions(string srev)
    {

        // longestPalindromicSubsequnce=LCS(s,srev)
        // LCS->
        // dp[n1+1][n2+1]
        // base case if any of string is empty dp[i][j]=0
        // if same
        // then dp[i][j] = 1+dp[i-1][j-1]<-digonal
        // else
        // dp[i][j]=max(dp[i-1][j],dp[i][j-1]) <-max(up,left)

        int n = srev.size();
        string s = srev;
        reverse(srev.begin(), srev.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < n; i++)
            dp[0][i] = dp[i][0] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == srev[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return n - dp[n][n]; //(n-longestPalindromicSubsequnce)=number of insertions
    }
};