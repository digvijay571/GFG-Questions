
//Longest Repeating Subsequence
//SUBSEQUENCE:
//Two strings
//same or not same charaters at i and j
//if same then take i+1,j+1
//if not same then move (i ->i+1) and stay j->j  or
//stay i -> i and move j -> j+1

int lcs(int n1, int n2, string &st, vector<vector<int>> &dp)
{
    if (!n1 || !n2)
        return 0;

    if (dp[n1][n2] != -1)
        return dp[n1][n2];

    if (st[n1 - 1] == st[n2 - 1] && n1 - 1 != n2 - 1)
        return dp[n1][n2] = 1 + lcs(n1 - 1, n2 - 1, st, dp);

    return dp[n1][n2] = max(lcs(n1 - 1, n2, st, dp), lcs(n1, n2 - 1, st, dp));
}

int longestRepeatingSubsequence(string st, int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return lcs(n, n, st, dp);
}

//Maximum subarray product
// An array c is a subarray of array d if c can be obtained from d by deletion of
//  several elements from the beginning and several elements from the end. or a contiguous section of a array

// Subproblem for the DP here would be:
// What is the maximum and minimum product we can get for a contiguous
// sub-array starting from the 0th to the current element? Why do we need to
// maintain the minimum product while we are asked for a maximum?
// The fact is that elements in nums can be negative, so it possible that
// for some negative element the previous
// min possible product can turn the current product into a greater value.
int maximumProduct(vector<int> &arr, int n)
{

    int maxproduct = arr[0];
    int minproduct = arr[0];
    int res = arr[0];

    //maxproduct and minproduct are maximum and minimum product from all subarrays ending at that index
    //not the maxproduct and minproduct untill that index
    for (int i = 1; i < n; i++)
    {

        int maxCurrProduct = max(minproduct * arr[i], max(arr[i], maxproduct * arr[i]));
        int minCurrProduct = min(minproduct * arr[i], min(arr[i], maxproduct * arr[i]));
        maxproduct = maxCurrProduct;
        minproduct = minCurrProduct;

        res = max(res, maxproduct);
    }

    return res;
}

//Ninja At Jym-similar to LIS

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    //dp[i] denotes maximumORLargestIncresingSubsequenceSumEndingAti
    vector<int> dp(n, 0);

    int ans = rack[0]; //for calculating the maximum sum

    dp[0] = rack[0];
    for (int i = 1; i < n; i++) //one loop is for calculating dp[i]
    {
        dp[i] = rack[i];            //dp[i]=1;initialization as
        for (int j = 0; j < i; j++) //calculating current problem dp[i]
                                    //using subproblem dp[j]:dp[0]...dp[i-1]
        {
            if (rack[i] > rack[j]) //can current element rack[i] can be attached
                //after the subsequnce ending at j
                //as the subsequece is increasing so
                //rack[i]>rack[j]
            {
                dp[i] = max(dp[i], rack[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]); //maximizing ans
    }
    return ans;
}
// Count Subarrays Having Product Less Than K
//Variable Sliding Windows
int countSubarrays(vector<int> &arr, int k)
{
    int n = arr.size(), start = 0, end = 0, counter = 0;
    long long product = 1;

    // Move window to count number of subarrays having product less than 'K'.
    while (end < n)
    {
        // Check and Move right bound of window further.
        if (product * arr[end] < k)
        {
            product = product * arr[end];
            end++;
            // Add count of subarrays having product less than 'K' and end at index 'end-1' in 'counter'.
            counter += end - start;
        }
        else
        {
            if (start == end)
            {
                // Corner case.
                start++;
                end++;
            }
            else
            {
                // Move left bound of window further.
                product = product / arr[start];
                start++;
            }
        }
    }

    return counter;
}

// Total Strings
//Stock based choices
const int MOD = 1000000007;

int count(int n, int b, int c, vector<vector<vector<int>>> &dp)
{

    if (n == 0)
        return 1;
    //take b
    if (dp[n][b][c] != -1)
        return dp[n][b][c];
    int take_b = 0, take_c = 0;

    if (b > 0) //if there is stock of b
        take_b = count(n - 1, b - 1, c, dp) % MOD;
    //take c
    if (c > 0) //if there is stock of c
        take_c = count(n - 1, b, c - 1, dp) % MOD;

    //take a
    int take_a = count(n - 1, b, c, dp) % MOD;

    return dp[n][b][c] = (take_a + take_b + take_c) % MOD;
}

int countStrings(int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return count(n, 1, 2, dp);
    // Write your code here.
}

//Longest Valid Parentheses -Using Stack
// The stack will tell us if the string scanned so far is valid or not.
// if the stack is empty, push the current index in it.
//  Otherwise, we have found a valid substring.
//  Find its length by subtracting the current index from the top element.
// pushing the indices, instead of characters, we can also determine the length of the longest valid substring.

//When we find open bracker

//Basically i am calculating at every index what is the maximum lenth of valid parentheses can be fromed ending at that index
//if open then push
//if close then pop and
//if the stack is empty then we cannot form any valid substring ending at that index,so push that index as a marker for next lenght
//if stack is not empty then we can calculte lenght using top of stack
int longestValidParentheses(string s)
{
    int ans = 0;

    stack<int> stk;
    stk.push(-1); //index stack to find len

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            // Push the current index.
            stk.push(i);
        }
        else
        {
            stk.pop(); //THIS IS KEY STEP
            if (stk.empty())
            {
                // Push the current index.
                stk.push(i);
            }
            else
            {
                // Found a valid substring. So, find its length.
                int len = i - stk.top();

                // Update the answer, if required.
                ans = max(ans, len);
            }
        }
    }

    return ans;
}

//Using open and close counter
int longestValidParentheses(string s)
{
    // Write your code here.
    int open = 0;
    int close = 0;

    int maxLen = 0;
    for (auto c : s)
    {
        if (c == '(')
            open++;
        if (c == ')')
            close++;
        if (open == close)
        {
            maxLen = max(open + close, maxLen);
        }
        else if (close > open)
        {
            open = 0;
            close = 0;
        }
    }
    open = 0;
    close = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {

        if (s[i] == ')')
            open++;
        if (s[i] == '(')
            close++;
        if (open == close)
        {
            maxLen = max(open + close, maxLen);
        }
        else if (close > open)
        {
            open = 0;
            close = 0;
        }
    }
    return maxLen;
}

//2keys keyboard and 4 keys keyboard

//2keys Keyboard
// https://leetcode.com/problems/2-keys-keyboard/

//Basically we have two choices :
//either use prev buffer
//or copy current entire string and paste it
long long int minSteps(int count, int bufferA, int total, vector<vector<long long int>> &dp)
{

    if (count == total)
        return 0;

    if (count >= total)
        return INT_MAX;

    if (dp[count][bufferA] != -1)
        return dp[count][bufferA];

    // copying current and pasting
    long long int copyandPaste = 2 + minSteps(2 * count, count, total, dp);

    long long int paste = INT_MAX;

    //using prev buffer
    if (bufferA > 0)
        paste = 1 + minSteps(count + bufferA, bufferA, total, dp);

    return dp[count][bufferA] = min(copyandPaste, paste);
}

class Solution
{
public:
    int minSteps(int n)
    {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(n + 1, -1));
        return ::minSteps(1, 0, n, dp);
    }
};

//Keypad count-Mike and mobile
// https://www.codingninjas.com/codestudio/problems/mike-and-mobile_1082139?topList=top-dynamic-programming-questions&leftPanelTab=2
//Using count method -dfs

long long int mod = 1e9 + 7;

int Count(int n, int i, int j, vector<vector<vector<int>>> &dp)
{

    //mistake happend was - i wrote success first and  faliure after which is wrong

    //failure
    if ((i == 3 && j == 0) || (i == 3 && j == 2) || i < 0 || j < 0 || i >= 4 || j >= 3)
        return 0;

    //success
    if (n == 0)
        return 1;

    if (dp[n][i][j] != -1)
        return dp[n][i][j];

    //same
    return dp[n][i][j] = (Count(n - 1, i, j, dp) % mod +     // same key
                          Count(n - 1, i + 1, j, dp) % mod + //adjacents//
                          Count(n - 1, i, j + 1, dp) % mod +
                          Count(n - 1, i - 1, j, dp) % mod +
                          Count(n - 1, i, j - 1, dp) % mod) %
                         mod;
}

int generateNumbers(int n)
{
    int count = 0;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(3, -1)));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            count += Count(n - 1, i, j, dp); //IMP: n-1 because i have included that one pressed one key here
            count = count % mod;
        }
    }

    return count % mod;
}

//Using valid state concept - Always going to valid state - BEST

const int mod = 1000000007;

int generateNumbersHelper(int count, int r, int c, int n, vector<vector<int>> &dp, vector<vector<int>> &keypad, vector<int> &dr, vector<int> &dc)
{
    if (count == n)
    {
        return 1;
    }

    if (dp[count][keypad[r][c]] != -1)
    {
        return dp[count][keypad[r][c]];
    }

    // Use long long to avoid int overflow.
    long long int ans = 0;

    for (int i = 0; i < dr.size(); i++)
    {
        int tr = r + dr[i];
        int tc = c + dc[i];
        if (tr >= 0 && tr < keypad.size() && tc >= 0 && tc < keypad[0].size() && keypad[tr][tc] != -1)
        {
            ans = (ans + generateNumbersHelper(count + 1, tr, tc, n, dp, keypad, dr, dc)) % mod;
        }
    }

    dp[count][keypad[r][c]] = ans;

    return ans;
}

int generateNumbers(int n)
{
    vector<vector<int>> keypad{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    vector<int> dr{0, 0, -1, 0, 1};
    vector<int> dc{0, -1, 0, 1, 0};
    // Stores the number of buttons pressed.
    int count;

    // R stores the row of previous pressed button.
    // C stores the column of previous pressed button.
    int r, c;

    // Stores the total numbers that can be generated.
    // Use long long to avoid int overflow.
    long long int ans = 0;

    vector<vector<int>> dp(n, vector<int>(10, -1));

    for (int i = 0; i < keypad.size(); i++)
    {
        for (int j = 0; j < keypad[0].size(); j++)
        {
            if (keypad[i][j] != -1)
            {
                count = 1;
                r = i;
                c = j;
                ans = (ans + generateNumbersHelper(count, r, c, n, dp, keypad, dr, dc)) % mod;
            }
        }
    }
    return ans;
}

//Unbounded Knapsack

int uknapsack(int n, int c, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    //if no items left and capacity can be zero or greater then zero
    if (n == 0)
        return 0;

    if (dp[n][c] != -1)
        return dp[n][c];

    //if current weight is
    if (weight[n - 1] > c)
        return dp[n][c] = uknapsack(n - 1, c, profit, weight, dp);

    int take_wt = profit[n - 1] + uknapsack(n, c - weight[n - 1], profit, weight, dp);

    int not_take = uknapsack(n - 1, c, profit, weight, dp);

    return dp[n][c] = max(take_wt, not_take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    return uknapsack(n, w, profit, weight, dp);
}

// Ninja the Exam Instructor
// https://www.codingninjas.com/codestudio/problems/ninja-the-exam-instructor_1215010?topList=top-dynamic-programming-questions&leftPanelTab=1
//Tree Sitting

#include <bits/stdc++.h>

//key idea is to maintain canSit

map<pair<Examcentre<int> *, int>, int> dp; //Using map : IMP

int count(Examcentre<int> *root, int canSit)
{
    if (root == NULL)
        return 0;

    if (dp.count({root, canSit}) return dp[{root, canSit}];
    
    int sit = 0;
    if (canSit) 
        sit = 1 + count(root->left, 0) + count(root->right, 0);

    int donotSit = count(root->left, 1) + count(root->right, 1);

    return dp[{root, canSit}] = max(sit, donotSit);
}

int examInstructor(Examcentre<int> *root)
{
    return count(root, 1);
}

//Choose Students
// https://www.codingninjas.com/codestudio/problems/choose-students_1062724?topList=top-dynamic-programming-questions&leftPanelTab=0

//nCr = n-1Cr+n-1Cr-1; //recurrence
//Base conditions if(n<r) return 0;
//     if(n==r || r==0) return 1;
int nCr(int n, int r, vector<vector<int>> &dp)
{
    if (n < r)
        return 0;
    if (n == r || r == 0)
        return 1;

    if (dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = nCr(n - 1, r - 1, dp) + nCr(n - 1, r, dp);
}

int choose(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
    return nCr(n, r, dp);
}

// Minimum Jumps
// https://www.codingninjas.com/codestudio/problems/minimum-jumps_1062693?topList=top-dynamic-programming-questions&leftPanelTab=0

int minimumJumps(vector<int> &arr, int n)
{
    //Idea is to use greedy:
    //Maintain three vars
    //maxReach -maximum reach from all prev steps
    //currReach-Reach in current jump
    //jump-to calculate jumps

    //Base case :IMP
    if (n == 1)
        return 0;

    //Initalize variables
    int maxReach = arr[0];
    int jumps = 1;
    int currReach = arr[0];

    for (int step = 1; step < n; step++)
    {
        //check for valid step:validation check
        if (step > maxReach)
            return -1;
        //reached end
        if (step >= n - 1)
            return jumps;
        //maximizing maxReach
        maxReach = max(maxReach, step + arr[step]);

        if (step == currReach) //we have to take a jump if step==currReach
        {
            currReach = maxReach;
            jumps++;
        }
    }
}

//Minimum Removals

// The key observation here is that the best way to remove an element from the array is to remove the maximum or minimum element from the array. There are two possible ways of removal, either we remove the minimum element or the maximum element.

// Now, the idea is to use recursion to reduce the big problem into several small subproblems.

// Here is the algorithm :

// We sort the array in ascending order.
// We will call a minRemovals function that returns us the minimum number of elements that should be removed such that the difference between the maximum element and minimum element of the remaining array is less than or equal to K. The minRemovals function will work as follows (here i and j denotes starting and ending index of ARR):
// If i >= j
// Return 0.
// If ARR[j] - ARR[i] <= K
// Return 0.
// Finally, we do a recursive call for (i + 1, j) and (i, j - 1) and 1 + minimum of them will be our answer.

//My bruteforce

#include <bits/stdc++.h>
int minimumRemovals(vector<int> &arr, int n, int k)
{

    sort(arr.begin(), arr.end());

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) //start loop
    {
        for (int j = 0; j < n; j++) //end loop
        {
            if (arr[j] - arr[i] <= k)
            {
                ans = min(ans, n - (j - i + 1));
            }
        }
    }
    return ans;
}

//Memoized

#include <bits/stdc++.h>
int minRem(int i, int j, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    //if single element left then
    if (i >= j)
        return 0;

    //if diff of min and max element is less than or equals to k

    if (arr[j] - arr[i] <= k)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int removeMin = 1 + minRem(i + 1, j, arr, k, dp);
    int removeMax = 1 + minRem(i, j - 1, arr, k, dp);
    return dp[i][j] = min(removeMin, removeMax);
}
int minimumRemovals(vector<int> &arr, int n, int k)
{

    sort(arr.begin(), arr.end());

    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minRem(0, n - 1, arr, k, dp);
}


//Combinations or  ubknapsack


//As target is given so problem is of Knapsack

int count(int n,int target,vector<int>& coins,vector<vector<int>>& dp)
{
   
   //as we have to find equal to target so target ==0 is going to be first condition i.e target is made return 1 combination
    //if it was capacity then we do not care about this-until target

    if(target==0) return 1;

    //base case if no elements left and target is not zero then return 0 
    if(n==0) return 0;
    
    if(dp[n][target] !=-1) return dp[n][target];
    
    int take = 0;
    //boundary check
    if(target>=coins[n-1])
    take=count(n,target-coins[n-1],coins,dp);
    
    int not_take = count(n-1,target,coins,dp);
    
    //count=choice1+choice2
    return dp[n][target]=take+not_take;
}

int countWays(int n){
    vector<int> coins = {3,5,10};
    vector<vector<int>> dp(4,vector<int>(n+1,-1));
    return count(3,n,coins,dp);
}
