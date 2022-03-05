class Solution {
public:
// dp[0] means, when we meet the current num n with index i. From A[0] to A[i], we can gather the max sum that divided by the remainder of 3 is 0;
// dp[1] means, when we meet the current num n with index i. From A[0] to A[i], we can gather the max sum that divided by the remainder of 3 is 1;
// dp[2] means, when we meet the current num n with index i. From A[0] to A[i], we can gather the max sum that divided by the remainder of 3 is 2;
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3,0);
     
        for(int i=0;i<n;i++){
            int x = dp[0] + nums[i];
            int y = dp[1] + nums[i];
            int z = dp[2] + nums[i];

            dp[x%3] = max({dp[x%3],x});
            dp[y%3] = max({dp[y%3],y});
            dp[z%3] = max({dp[z%3],z});
            
        }
        return dp[0];
    }
};

// [3,6,5,1,8]





14
5
5