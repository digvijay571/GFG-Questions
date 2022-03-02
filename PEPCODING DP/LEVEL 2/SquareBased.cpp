
// Count All submatix with all 1s

// Basic Intution:
// with the given A[i][j] the what is the maximum possible length of the square we can construct..
// This intution gives an insight towards solving the problem.

// For constucting a square we need left side point, upper point and diagonal point required [Hope you are able to visualise!]

// image:https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/643420/Count-Square-Submatrices-with-All-Ones-CPPC%2B%2BDPWell-explainedEasy-to-understand

// But, Our question is not about finding the maximum length of square. its about how many squares possible.
// this is nothing but count all maximum possible size at each point (nothing but each and every element).

// Function Explanation:
// int countSquares(vector<vector>& matrix) {

// Get the number of rows
// Get the number of columns.
// declare a variable to store our ans: submatrices_with_all_ones = 0
// take a vector of same size of matrix, and called it as dp and intialised to 0

// if matrix[i][j] is 1 then including that as a corner elmeent
// if dp[i][j] gives maximul length of square that can be formed using that as a corner element
// we can form L possible unique squares

// fill the dp matrix with dp[i][j] = 1+ min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
// and sum of all possible squares

// EG:

// if length be 3

//                __
//               |__| <--corner element

//             __ __
//            |__|__|
//            |__|__| <--corner element

//          __ __ __
//         |__|__|__|
//         |__|__|__|
//         |__|__|__| <--corner element

// So we can form 3 matrix including the rightbottom     for len 3
