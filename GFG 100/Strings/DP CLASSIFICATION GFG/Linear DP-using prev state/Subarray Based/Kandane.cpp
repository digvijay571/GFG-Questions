// dynamic programming
// . The idea is to calculate, for each index :
//dp[i] the maximum sum of a subarray that with  nums[i].

//dp[i]=max(nums[i],dp[i-1]+nums[i]);//prevsum+nums[i], 

//we can manitain prev variable instead of dp array as 
//dp depents on dp[i-1] only

// Largest Subarray Sum
int smallestSubarraySum(int a[], int n)
{

    int sum = a[0];
    int ans = a[0];
    for (int i = 1; i < n; ++i)
    {
        sum = max(a[i], a[i] + sum);
        ans = max(ans, sum);
    }

    return ans;
}

// . The idea is to calculate, for each index :
// the minimum sum of a subarray that ends at that index.

// Smallest Subarray Sum
int smallestSubarraySum(int a[], int n)
{

    int sum = a[0];
    int ans = a[0];
    for (int i = 1; i < n; ++i)
    {
        sum = min(a[i], a[i] + sum);
        ans = min(ans, sum);
    }

    return ans;
}