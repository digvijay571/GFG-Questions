// Identification?
// Subarray or SubString
// Window Size / Condition(max/minimize)
// finding longest substring or shortest substring with some contraints are mostly based on sliding window.

// We cannot apply sliding window in problem like: https://leetcode.com/problems/contiguous-array/
//  This is because there is no proper concrete condition where we can increase or decrese the boundary condition. For such problems, we apply hash-map.
// OR it converts to prefix map problem

// Maximum-K size-Sum subarray
// Maximum in every K window
// negative in every K window
// Anagram of a given String?

//
//
//

// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// https://leetcode.com/problems/max-consecutive-ones-iii/
// https://leetcode.com/problems/subarrays-with-k-different-integers/
// https://leetcode.com/problems/fruit-into-baskets/
// https://leetcode.com/problems/get-equal-substrings-within-budget/
// https://leetcode.com/problems/longest-repeating-character-replacement/
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// https://leetcode.com/problems/minimum-size-subarray-sum/
// https://leetcode.com/problems/sliding-window-maximum/

// Count Anagrams
//  Pick toys
//  Longest Substring without repeating characters
//  Longest substring with K unique characters
//  Minimum window substring

// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1/

int maximumSumSubarray(int k, vector<int> &arr, int N)
{
    int start = 0;
    int end = 0;

    int sum = 0;
    int maxSum = arr[0];
    while (end < N)
    {
        sum += arr[end];

        if (end - start + 1 == k) // equal to window size
        {
            maxSum = max(sum, maxSum); // calculte ans
            sum -= arr[start];         // remove ans of starting
            start++;
        }
        end++;
    }
    return maxSum;
}
// FOllow UP:
// can be used to make a map for every lenght from 0 to n
//<len,maxSubArraySum>

// First negative integer in every window of size k
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1/

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> ans;

    int start = 0;
    int end = 0;
    deque<long long> dq;
    while (end < N)
    {
        //
        if (A[end] < 0)
        {
            dq.push_back(end);
        }

        if (end - start + 1 == K)
        {
            if (dq.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(A[dq.front()]);
                if (K <= end - dq.front() + 1)
                    dq.pop_front();
            }
            start++;
        }
        end++;
    }

    return ans;
}

// https://leetcode.com/problems/sliding-window-maximum/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (k == 1)
        return nums;

    int start = 0; // start of window
    int end = 0;   // end of window

    deque<int> dq;
    vector<int> ans;
    while (end < nums.size())
    {

        // calculations
        if (dq.empty())
        {
            dq.push_back(end);
        }
        else
        {
            while (!dq.empty() && nums[dq.back()] < nums[end])
            {
                dq.pop_back();
            }
            dq.push_back(end);
        }

        if (end - start + 1 == k)
        {
            ans.push_back(nums[dq.front()]);
            if (k <= end - dq.front() + 1)
            {
                dq.pop_front();
            }
            start++;
        }
        end++;
    }
    return ans;
}

Variable sliding window : https :
    // https://leetcode.com/problems/minimum-size-subarray-sum/discuss/59110/O(N)-template-for-Minimum-Size-Subarray-Sum-and-Minimum-Window-Substring-and-Longest-Substring-Without-Repeating-Characters
    // find all subarrays with product less than or equal to k
    //  https://leetcode.com/problems/minimum-size-subarray-sum/
    class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = INT_MAX;
        int start = 0;
        int end = 0;

        int sum = 0; // for finding sum
        while (end < nums.size())
        {
            sum += nums[end]; // calculate sum

            while (sum >= target) // condition given in the question
            {
                if (end - start < len)
                    len = end - start + 1; // calcutate size of current window and minimizing
                sum -= nums[start];
                start++; // shirinking the window
            }
            // increasing window size
            end++;
        }
        return (len != INT_MAX) ? len : 0;
    }

    class Solution
    {
    public:
        int minSubArrayLen(int s, vector<int> &nums)
        {
            int start = 0, end = 0;
            int minLen = INT_MAX, sum = 0;
            while (end < nums.size())
            {
                if (sum < s)
                    sum += nums[end];
                end++;
                while (sum >= s)
                {
                    if (end - start < minLen)
                        minLen = end - start;
                    sum -= nums[start];
                    start++;
                }
            }
            return minLen == INT_MAX ? 0 : minLen;
        }
    };
    Next, let me show you the solution to the problem "Minimum Window Substring"

        class Solution
    {
    public:
        string minWindow(string s, string t)
        {
            vector<int> v(128, 0);
            for (auto c : t)
                v[c]++;
            int start = 0, end = 0, counter = t.size();
            int m_start = 0, m_len = INT_MAX;
            while (end < s.size())
            {
                if (v[s[end]] > 0)
                    counter--;
                v[s[end]]--;
                end++;
                /** loop from start to check whether we can find more short string **/
                while (counter == 0)
                {
                    if (m_len > end - start)
                    {
                        m_start = start;
                        m_len = end - start;
                    }
                    v[s[start]]++;
                    if (v[s[start]] > 0)
                        counter++;
                    start++;
                }
            }
            return m_len == INT_MAX ? "" : s.substr(m_start, m_len);
        }
    };
The solution for the problem "Longest Substring Without Repeating Characters" can also be solved in the

same pattern .

Here is the solution for "Longest Substring Without Repeating Characters"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> v(128, 0);
        int start = 0, end = 0;
        int m_len = INT_MIN;
        while (end < s.size())
        {
            if (v[s[end]] == 0)
                m_len = max(m_len, end - start + 1);
            v[s[end]]++;
            end++;
            while (v[s[end]] > 0)
            {
                v[s[start]]--;
                start++;
            }
        }
        return m_len == INT_MIN ? 0 : m_len;
    }
};
As you can see, they all follow the same pattern !

    // Counting Questions ->
    //  https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

    class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        vector<int> fmp = {0, 0, 0};

        int start = 0; // start of window
        int end = 0;   // ending of window

        int count = 0;
        while (end < n)
        {
            // calculation to satify the condition
            fmp[s[end] - 'a']++;

            while (fmp[0] > 0 && fmp[1] > 0 && fmp[2] > 0) // condition given in question
            {
                count += n - end; // doing n-end to count all the subarrays containing these charater i.e. [[start...end]+something]
                                  // and start is fixed:IMP

                // removing the calculation of start
                fmp[s[start] - 'a']--;
                start++; //   moving start //shrinking the window NOT sliding as it is a while it will silde when condition gets voilated
            }
            end++; // increasing size of window
        }

        return count;
    }
};

// Count Subarrays Having Product Less Than K
// Variable Sliding Windows
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

// General template

// while(end<n)
{
    // calculation - hash map or counter etc.

    // end++ here OR ? does it matter-eg len will be for this case is end-start?

    if ()
        or while () // when to calculte ans and HOW?
    // calculte ans?
    // remove the calculation of starting
    // slide then window if possible

    // end++ here OR? does it matter-eg len will be for this case is end-start+1?
}

// https://leetcode.com/problems/max-consecutive-ones-iii/

// In this question end++ has to be done before
// as if k is zero and next is 1 it is also valid
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        // key is how calculate and when will we get our ans and till when to
        // when k is zero- as we are asked maximum len

        int n = nums.size();
        int start = 0;
        int end = 0;

        int len = 0;
        while (end < n)
        {
            // calculation
            if (nums[end] == 0 && k)
                k--;                       // flip
            else if (!k && nums[end] == 0) // if no stockand it is 0 then simply move start
            {
                start++;
            }
            end++;
            if (k >= 0) // calculte length >= not == as it is possible to have ans in > case also
            {
                len = max(len, end - start);

                while (end < n && k == 0 && nums[end] == 0) // shrinking the window to get stock
                                                            // and it will slide when the condition gets voilated
                                                            // as we are using end index so end<n should be present
                {
                    if (nums[start] == 0)
                        k++; // unfip from start
                    start++;
                }
            }
        }

        return len;
    }
};

// Shorter one:)
int longestOnes(vector<int> &nums, int k)
{

    int n = nums.size();
    int start = 0;
    int end = 0;

    int len = 0;
    while (end < n)
    {

        if (nums[end] == 0)
            k--; // flip

        while (k < 0) // k can be mimimum zero so..
        {
            if (nums[start] == 0)
                k++; // unfip from start
            start++;
        }
        len = max(len, end - start + 1);
        end++;
    }

    return len;
}