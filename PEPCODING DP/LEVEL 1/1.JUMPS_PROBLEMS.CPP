// same choice on each step:

// 1.Climbing-stairs
//  https://leetcode.com/problems/climbing-stairs/

// we have to some how know what are the choices to jump from current position
// it can be constant
// or diffrent for each step

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        if (n == 1 || n == 2)
            return n;

        // base cases-observation based
        dp[1] = 1;
        dp[2] = 2;
        // dp[i] gives ways to reach i th step
        // dp[n] will give ways to reach n
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2]; // recurrence-> from i-1 by doing one jump reach i
                                           // from i-2 by doing two jump reach i
                                           // total ways ways(i)= ways(i-1)+ways(i-2)
        }
        return dp[n];
    }
};

// Climbing Stairs with Minimum Jumps
// https://leetcode.com/problems/jump-game-ii/submissions/

// It is given in the question that we will always reach end

// We can tabulate it by starting from end
class Solution
{
public:
    long long int minjumps(int start, int end, vector<int> &nums, vector<int> &dp)
    {
        if (start == end)
            return 0;
        // Imp:base case
        if (nums[start] == 0)
            return INT_MAX;

        if (dp[start] != -1)
            return dp[start];
        long long int ans = INT_MAX; // IMP:as we have to minimize so INT_MAX
                                     // take return val as long long int (overflow precaution)
        for (int step = 1; step <= nums[start] && start + step <= end; step++)
        {

            ans = min(ans, 1 + minjumps(start + step, end, nums, dp)); // cotribution+call()
        }

        return dp[start] = ans;
    }

    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return minjumps(0, n - 1, nums, dp);
    }
};

// Minimum Jumps
// https://www.codingninjas.com/codestudio/problems/minimum-jumps_1062693?topList=top-dynamic-programming-questions&leftPanelTab=0

int minimumJumps(vector<int> &arr, int n)
{
    // Idea is to use greedy:
    // Maintain three vars
    // maxReach -maximum reach from all prev steps
    // currReach-Reach in current jump
    // jump-to calculate jumps

    // Base case :IMP
    if (n == 1)
        return 0;

    // Initalize variables
    int maxReach = arr[0];
    int jumps = 1;
    int currReach = arr[0];

    for (int step = 1; step < n; step++)
    {
        // check for valid step:validation check
        if (step > maxReach)
            return -1;
        // reached end
        if (step >= n - 1)
            return jumps;
        // maximizing maxReach
        maxReach = max(maxReach, step + arr[step]);

        if (step == currReach) // we have to take a jump if step==currReach
        {
            currReach = maxReach;
            jumps++;
        }
    }
}

// template For jumpls problem:we can easily convert this to dp table

int jump(int end)
{
    if (end == 0)
        return 1; // reached starting

    if (end == somewhere) // where i cannot jump (eg jump=0 or sticky step) so return INT_MAX or According to question
        return INT_MAX;
    int count = 0;                                                         // counting for current subproblem
    for (int step = 1; step <= max_jumps && (end - step >= start); step++) // loop for possible jumps at current step
    {
        count += jump(end - step);

        // IMP:to print path
        // take a path string
        // path.push_back(step)
        //  jump(end - step)
        // path.pop_back();//while backtrack undo the change and move for next step
    }

    return count;
}

// Frog jump

// GIveaway from error: we cannot make Dp table for large values e.g INT_MAX if given and we are using as one of variables to memoize
// then space complexity will not be enough or Might give out of bound due to INT_MAX+1

// https://leetcode.com/problems/frog-jump/discuss/1798336/Java-O(n-*-k)-or-Memoization-or-Dynamic-Programming

// UNDERLYING REQUIREMENT:

// Check if any path exists between source node and destination node
// Given is a DAG:
//  * A node is a 'stone-jumpSize' state.
//  * 'Neighbours of a node' (aka edge) is all other stones having jumpSizes d, d - 1 and d + 1, where d is the distance between current node's stone and other stone
//  * The nodes and edges (aka states and relations) are difficult recognize. Only test cases can help in defining them. Checkout image at bottom
//  * Direction is forward and so no cycles.
//  * Considering 3 branches come out from each node (and graph is acyclic as mentioned above), junctions (overlapping states) are possible.
// APROACH | TIME | SPACE:

// Method 1: explore all paths

// Dfs | O(3^n) | n recursive stacks
// Method 2: Since graph is a DAG, its safe to cache overlapping suboroblems:

// Dp + Linear Search + skip duplicates | O(n³) | O(n²) https://leetcode.com/problems/frog-jump/discuss/1782317/Binary-Search-With-DP-oror-C%2B%2B-With-Comments-Explanation
// Dp + Binary search + skip duplicates | O(n²logn) | O(n²)
// Dp + HasSet | O(n²) | O(n²)
// Method 3: Since the requirement is to check if any path exists between source and destination, better search in the shortest possible way

// BFS | O(n²) | O(n²)
// Referenece:https://leetcode.com/problems/frog-jump/discuss/1663524/Java-oror-HashMap-(DP)-%2B-BFS-oror-Explained

// DP: wasabistudio
// STATES AND RELATIONS IN DP (aka nodes and edges in graph)