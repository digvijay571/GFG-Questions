//simple partition whenever condition satisfied



//K partions
// https://leetcode.com/problems/largest-sum-of-averages/

class Solution {
public:
    
    //for the last partition
     double avg(int start, vector<int>& A) {
        int end=A.size() - 1;
        double sum = 0;
        for (int i = start; i <= end; i++) sum += A[i];
        return sum / (end - start + 1);
    }
    
  //i->start
  //j->end
  double solve(int i, vector<int>& nums, int K, vector<vector<double>>& memo) {
     
        if (i >= nums.size()) return 0;//do i reahed end?
        
        if (K == 1) return avg(i, nums);//done k-1 partions..
      
        if (memo[i][K] != -1) return memo[i][K];
      
        double sum = 0;//used for finding avg of current partition
      
        int max_group_size = nums.size()-K; // max elements in the group for the given K
      
        //
        for (int j = i; j <= max_group_size; j++) {
            sum += nums[j];
                                        //contribution of avg for current partion and recusively calling to get minimum avg sum for remaining partions
            memo[i][K] = max(memo[i][K], sum / (j - i + 1) + solve(j + 1, nums, K - 1, memo));
        }
        return memo[i][K];
    }
    
   
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<vector<double>> dp(n,vector<double>(k+1,-1));
        return solve(0,nums,k,dp);
    }
};


// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

class Solution {
public:

    //for the last partition
     int lastday(int start, vector<int>& A){
        return *max_element(A.begin()+start,A.end());
    }
    
  //i->start
  //j->end
  int solve(int i, vector<int>& nums, int K, vector<vector<int>>& memo) {
     
        if (i >= nums.size()) return 0;//do i reahed end?
        
        if (K == 1) return lastday(i, nums);//done d-1 partions(days)..
      
        if (memo[i][K] != -1) return memo[i][K];
      
        int cmax = 0;//used for finding avg of current partition
      
        int max_group_size = nums.size()-K; // max elements in the group for the given K
      
        //
        int ans=INT_MAX;
        for (int j = i; j <= max_group_size; j++) {
            cmax = max(cmax,nums[j]);
                                        //contribution of difficulty and recusively calling to get minimum difficulty sum for remaining partions
            ans = min(ans, cmax + solve(j + 1, nums, K - 1, memo));
        }
        return memo[i][K]= ans;
    }
    
    //nums->difficulty
    int minDifficulty(vector<int>& nums, int d) {
         int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
       int ans= solve(0,nums,d,dp);
       return (ans==INT_MAX) ? -1:ans;
    }
};









//Type-3 ->max K len partion


//end<min(start+k,n) 
class Solution {
public:
   // length at most k
    int solve(int start,vector<int>& nums,int k,vector<vector<int>>& dp)
    {
        
        int n=nums.size();
        
        if(start>=n) return 0;

        if(dp[start][k] !=-1 )return dp[start][k];
        
        int sum=0;
        int currmax=0;
        for(int end=start;end<min(start+k,n);end++)
        {
             currmax= max(currmax,nums[end]);
             sum =max(sum, currmax*(end-start+1)+solve(end+1,nums,k,dp));
        }
        return dp[start][k] = sum;
    }
    
    
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(0, nums, k, dp);
    }
};

