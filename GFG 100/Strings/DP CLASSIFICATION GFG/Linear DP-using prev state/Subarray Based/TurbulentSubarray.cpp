https : // leetcode.com/problems/longest-turbulent-subarray/
        class Solution
{
public:
    int maxTurbulenceSize(vector<int> &nums)
    {
        // idea is to maintain two states
        // prev len ending with pos diff
        // prev len ending with neg diff

        // if curr diff is less than zero then it can be appended to len of prev pos to make a wiggle sequence and reset pos=1
        // if curr diff is greater than zero then it can be appended to len of prev neg to make a wiggle sequence and reset neg=1
        // if curr diff=0 then reset both to 1
        int pos = 1;
        int neg = 1;
        int n = nums.size();
        int ans = 1;

        for (int i = 1; i < n; i++)
        {
            int currdiff = nums[i] - nums[i - 1];

            if (currdiff < 0)
            {
                neg = pos + 1; //
                pos = 1;
            }
            else if (currdiff > 0)
            {
                pos = neg + 1;
                neg = 1;
            }
            else
            {
                pos = 1;
                neg = 1;
            }
            ans = max({ans, neg, pos});
        }
        return ans;
    }
};