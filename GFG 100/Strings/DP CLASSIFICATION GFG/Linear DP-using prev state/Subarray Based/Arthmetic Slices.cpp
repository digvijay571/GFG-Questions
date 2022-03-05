
// https://leetcode.com/problems/arithmetic-slices/

// idea is to maintain dp[i] which represent arithmetinc slices ending at this index
class Solution
{
public:
    // https://leetcode.com/problems/arithmetic-slices/discuss/1814356/Java-or-3-liner-or-Explained
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        if (nums.size() < 3)
            return 0;

        int len = 2;
        int ans = 0;
        for (int i = 2; i < nums.size(); ++i)
        {

            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {

                len += 1;
            }

            else
            {
                ans += len - 2;
                len = 0;
            }
        }

        return;
    }
};

// https://leetcode.com/problems/number-of-substrings-with-only-1s/

class Solution
{
public:
    int numSub(string s)
    {

        int n = s.size();

        int prev = 0;
        int totalSubarrays = 0; // total subarray will be sum of all prev states
        for (int i = 0; i < n; ++i)
        {

            if (s[i] == '0') // reset prev to zero as there are no subarray of 1 ending at current index
            {

                prev = 0;
            }
            else
            {
                prev = (prev + 1) % m; // subarrays of 1 ending at current will be one greater than prev
                totalSubarrays = (totalSubarrays + prev) % m;
            }
        }

        return totalSubarrays;
    }
};

// Based on grouping and n*(n+1)/2;
class Solution
{
public:
    int numSub(string s)
    {

        int m = 1e9 + 7;
        int count = 0;

        int n = s.size();

        long long int total = 0;

        // as we know that the number of substring which can be formed in len N
        // N*(N+1)/2
        // taking each 1 group and summing up their substring count whenever zero comes and resetting count to zero
        // at last if there is some count left that means we have not considered the last group
        // so add substrings of that group too

        for (int i = 0; i < n; ++i)
        {

            if (s[i] == '0')
            {
                total += ((1LL * (count % m) * ((count + 1) % m)) % m) / 2;
                count = 0;
            }
            else
            {
                count += 1;
                count = count % m;
            }
        }

        total += (1LL * (count % m * (count + 1) % m) % m) / 2;

        return total;
    }
};
