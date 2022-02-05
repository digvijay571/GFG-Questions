
Variable sliding window : https :
    //leetcode.com/problems/minimum-size-subarray-sum/discuss/59110/O(N)-template-for-Minimum-Size-Subarray-Sum-and-Minimum-Window-Substring-and-Longest-Substring-Without-Repeating-Characters
    //find all subarrays with product less than or equal to k

    // https://leetcode.com/problems/minimum-size-subarray-sum/
    class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = INT_MAX;
        int start = 0;
        int end = 0;

        int sum = 0; //for finding sum
        while (end < nums.size())
        {
            sum += nums[end]; //calculate sum

            while (sum >= target) //condition given in the question
            {
                if (end - start < len)
                    len = end - start + 1; //calcutate size of current window and minimizing
                sum -= nums[start];
                start++; //shirinking the window
            }
            //increasing window size
            end++;
        }
        return (len != INT_MAX) ? len : 0;
    }