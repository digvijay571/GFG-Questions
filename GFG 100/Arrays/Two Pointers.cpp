

// TWO SUM:

// https://techiedelight.com/practice/?problem=TwoSum
int twoSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        int sum = nums[l] + nums[r];
        if (sum == target)
        {
            return true;
        }
        else if (sum < target) //-(how to reduce increase sum the low++?)
        {
            l++;
        }
        else // sum>target-(how to decrease sum the high--?)
        {
            r--;
        }
    }
    return false;
}

// Find All pairs whose sum is eqaual to k
// https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Basically the code is same as two sum, when the sum is equal we do l++,r--
static List<(int, int)> FindAllPairs(int[] arr, int desiredSum)
{
    sort(arr.begin(), arr.end());
    List<(int, int)> pairs = new List<(int, int)>();
    int i = 0;
    int j = arr.Length - 1;

    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == desiredSum)
        {
            pairs.Add((arr[i], arr[j]));
            i++;
            j--;
        }
        else if (sum > desiredSum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return pairs;
}

// Two Sum - Unique pairs
// https://www.lintcode.com/problem/587
// HOw to remove duplicates ?
// as we find the pair we need to get to next unique elements for both the pointers l and r
//  while(l<n&& arr[l+1]==arr[l])l++;
// l++;
// while(r>=0&& arr[r-1]==arr[r])r--;
// r--;
int twoSum6(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int pairs = 0;
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == k)
        {
            pairs++;
            while (i < n && arr[i] == arr[i + 1])
                i++;
            i++;
            while (j >= 0 && arr[j - 1] == arr[j])
                j--;
            j--;
        }
        else if (sum > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return pairs;
}

// Two Sum - Closest to target
// Basically the code is same as two sum
// when sum ==target return 0
// else minimize the diffrence between target and sum
// and update  the sum

// https://www.lintcode.com/problem/533/description
int twoSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    int diff = INT_MAX;
    sort(nums.begin(), nums.end());
    while (l < r)
    {
        int sum = nums[l] + nums[r];
        if (sum > target)
        {
            diff = min(diff, abs(target - sum));
            r--;
        }
        else if (sum < target)
        {
            diff = min(diff, abs(target - sum));
            l++;
        }
        else
        {
            return 0;
        }
    }
    return diff;
}

// Count pairs in a sorted array whose sum is less than x  OR  Less than or equal to target
//
int findPairs(int arr[], int n, int x)
{
    int l = 0, r = n - 1;
    int result = 0;

    while (l < r)
    {
        // If current left and current
        // right have sum smaller than x,
        // the all elements from l+1 to r
        // form a pair with current l.
        if (arr[l] + arr[r] < x)
        {
            result += (r - l);
            l++;
        }

        // Move to smaller value
        else
            r--;
    }

    return result;
}

// Two Sum when input is BST:

// Two Sum when Two BST are given:

// V V.Imp : Greedy Two Pointers
//  Boats to Save People - LeetCode
//  https://leetcode.com/problems/boats-to-save-people/

// IDea is to sort the array:(idea is to make pair with the greatest and the smallest to make max pairs)
// If the weight of the two are greater than the limit then ...The greater element cannot sit in pair with any other element as it is not able to sit with the smallest element
// so high--
// if it is less than or equal to limit then take them in pair
// and high--,low++

int numRescueBoats(vector<int> &people, int limit)
{
    int n = people.size();
    sort(people.begin(), people.end());
    int i = 0;
    int j = n - 1;
    int count = 0;
    while (i <= j) // equal to miss-mistake
    {
        int weight = people[i] + people[j];
        if (weight > limit)
        {
            count++;
            j--;
        }
        else
        {
            count++;
            j--, i++;
        }
    }
    return count;
}

// https://leetcode.com/problems/bag-of-tokens/
// So, we sort the tokens first, and pick tokens left to right while we have enough power.
//  Otherwise, we pick tokens right to left to gain power.
// We repeat this until we use all tokes or have no more points
int bagOfTokensScore(vector<int> &tokens, int power)
{
    sort(tokens.begin(), tokens.end());
    if (tokens.size() == 0 || power < tokens[0])
        return 0;
    int score = 0, maxScore = 0;
    int left = 0, right = tokens.size() - 1;
    while (left <= right)
    {
        if (power < tokens[left])
        { // not enought power
            if (score > 0)
            {
                power += tokens[right--]; // right to left to gain power
                score--;
            }
            else
                return score;
        }
        else
        {
            power -= tokens[left++];
            score++;
            maxScore = max(score, maxScore);
        }
    }
    return maxScore;
}

// https://leetcode.com/problems/squares-of-a-sorted-array/
vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    vector<int> res(n, 0);
    int k = n - 1;
    // Idea is to take two pointers at start and end ..and whichever has greater square take it and move it
    // Idea is we know that the square of largest or smallest value will be max so whichever is max take it and move
    while (i <= j)
    {
        int a = nums[i] * nums[i];
        int b = nums[j] * nums[j];

        if (a > b)
        {
            res[k--] = a;
        }
        else
        {
            res[k--] = b;
        }
    }
    return res;
}
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
int numSubseq(vector<int> &A, int target)
{
    sort(A.begin(), A.end());
    int res = 0, n = A.size(), l = 0, r = n - 1, mod = 1e9 + 7;
    vector<int> pows(n, 1);
    for (int i = 1; i < n; ++i)
        pows[i] = pows[i - 1] * 2 % mod;
    while (l <= r)
    {
        if (A[l] + A[r] > target)
        {
            r--;
        }
        else
        {
            res = (res + pows[r - l++]) % mod;
        }
    }
    return res;
}

// SOme diffrent Two pointer Problems:
//  https://leetcode.com/problems/pancake-sorting/

// https://leetcode.com/problems/friends-of-appropriate-ages/
int numFriendRequests(vector<int> &ages)
{
    sort(ages.begin(), ages.end());
    int ans = 0, lo = 0, hi = 0;
    for (auto &x : ages)
    {
        for (; hi < ages.size() && x == ages[hi]; ++hi)
            ;
        for (; lo + 1 < hi && ages[lo] <= x / 2 + 7; ++lo)
            ;
        ans += hi - lo - 1;
    }
    return ans;
}

// Easy SIMPLE TWO POINTERS:

// Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
int maxArea(vector<int> &height)
{
    int n = height.size();
    int l = 0;
    int r = n - 1;
    int maxWater = 0;

    while (l < r)
    {
        maxWater = max(maxWater, min(height[l], height[r]) * (r - l));

        if (height[l] < height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    return maxWater;
}

// Move zeros
void moveZeroes(vector<int> &nums)
{
    // maintaining the relative order of the non-zero elements.
    int i = 0;
    int j = 0;
    while (j < nums.size())
    {
        if (nums[j] != 0)
            swap(nums[i++], nums[j]);

        j++;
    }
}
// Two way or Three way partitioning
// Reverse
// Palindrome

// SOme more important questions Asked?
// Remove Duplicates form unsorted and sorted array.
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int i = 0; // points to empty location
    int j = 0; // points to first unique char

    while (j < n)
    {
        int currchar = nums[j];
        swap(nums[i++], nums[j]);
        while (++j < n && nums[j] == currchar)
        {
        } // skip duplicates->mistake was doing j++ again inside loop
    }

    return i;
}

// Trapping Rain Water
https://www.youtube.com/watch?v=PwEdhxQkFZs&t=696s
//  https://leetcode.com/problems/trapping-rain-water/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        // remember to initalize with zero  not a[0] and a[n-1]
        int lmax = 0;
        int rmax = 0;
        int ans = 0;

        // remeber to start form 0 and n-1

        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax)
            {
                ans += lmax - height[l];
                l++;
            }
            else
            {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};



//Seating Arrangement Two Pointers
