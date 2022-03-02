// Subset I:https://leetcode.com/problems/subsets/
// Given an integer array nums of unique elements, return all possible subsets (the power set).
//  The solution set must not contain duplicate subsets. Return the solution in any order.
// choices for every i th element
//           i
// (take i) / \ (not take i)

class Solution
{
public:
    vector<vector<int>> ans;

    void generateSubsets(int n, vector<int> &subset, vector<int> &nums)
    {
        if (n == 0)
        {
            ans.push_back(subset);
            return;
        }
        // take
        subset.push_back(nums[n - 1]);
        generateSubsets(n - 1, subset, nums);
        subset.pop_back(); // to reach subset to original state as before

        // non-take
        generateSubsets(n - 1, subset, nums);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> subset;
        generateSubsets(n, subset, nums);
        return ans;
    }
};

//  Subset I:https://leetcode.com/problems/subsets-ii/submissions/

class Solution
{
public:
    vector<vector<int>> ans;
    void generateSubsets(int n, vector<int> &subset, vector<int> &nums)
    {
        if (n == 0)
        {
            ans.push_back(subset);
            return;
        }
        // take
        subset.push_back(nums[n - 1]);
        generateSubsets(n - 1, subset, nums);
        subset.pop_back(); // to reach subset to original state as before

        // skip duplicates
        while (n >= 2 && nums[n - 1] == nums[n - 2])
            n--;

        // non-take
        generateSubsets(n - 1, subset, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> subset;
        sort(nums.begin(), nums.end());
        generateSubsets(n, subset, nums);
        return ans;
    }
};

// Combination Sum I:https://leetcode.com/problems/combination-sum/
vector<vector<int>> ans;
void count(int n, int target, vector<int> &nums, vector<vector<int>> &dp, vector<int> &s)
{
    if (target == 0)
    {
        ans.push_back(s);
        return;
    }

    if (n == 0)
        return;

    // if(dp[n][target] !=-1) return dp[n][target];

    if (nums[n - 1] <= target)
    {
        s.push_back(nums[n - 1]);
        count(n, target - nums[n - 1], nums, dp, s);
        s.pop_back();
    }

    count(n - 1, target, nums, dp, s);
}

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        ans.clear();
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        vector<int> s;
        count(n, target, nums, dp, s);
        return ans;
    }
};





// Combination Sum I:https://leetcode.com/problems/combination-sum-ii/

vector<vector<int>> ans;
class Solution {
public:
    
void cS(int n,int target,vector<int>& nums,vector<int>& s)
{
    if(target==0){
        ans.push_back(s);
        return ;
    }
    
    if(n==0) return;
    
    if(nums[n-1]<= target){
         s.push_back(nums[n-1]);
         cS(n-1,target-nums[n-1],nums,s);
         s.pop_back();
        
        //skip duplicate starting points     
       while(n >=2 && nums[n-1]==nums[n-2]) {
           n--;     
       }
    }
      
    
        cS(n-1,target,nums,s);
}

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        ans.clear();
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> s;
        cS(n,target,nums,s);
        return ans;
    }
};