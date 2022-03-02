// Hint:Sorted

// https://www.youtube.com/watch?v=zr_AoTxzn0Y&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=5

// https://leetcode.com/tag/binary-search/

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/1132193/Four-problems-all-in-one-concept

// Binary Search-Searh element in Sorted Array

// IN Binary Search Tecnique we basically reduce the search space by comparing to mid- one half gets  eliminated because we are sure that ans will not be in it and we move to other half
// Logn - Complexity (adaha karte jate hai issliye logn,it is also a great hint for applying binary search)
// We have to find a funtion of form - TTTTFFFF or FFFFFTTTTT for the search space
// we can find last true or first false or vice versa

// how to write mid?
// mid = low - (low-high)/2; (in case if as lies in high half)
// mid = high - (high-low)/2; (in case if as lies in low half)

// Condition- low<high or low<=high or low+1 < high
// How to decide?

// Find element in sorted array
// https://leetcode.com/problems/binary-search/
int search(vector<int> &nums, int target)
{

    // nums is sorted

    int n = nums.size();

    // define boundaries
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        // calclate mid
        int mid = high - (high - low) / 2; // as we can see that in lower half mid is writeen so below so it will be of high

        if (nums[mid] <= target) // functioms: nums[m]<=target
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    return nums[low] == target ? low : -1; // sanity check
}

// Using half method
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        // nums is sorted

        int n = nums.size();

        // define boundaries
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            // calclate mid
            int mid = (start + end) / 2; // mid

            if (nums[mid] == target) // if equal then return index
            {
                return mid;
            }
            else if (nums[mid] > target) // if nums[mid]>target then move end
            {
                end = mid - 1;
            }
            else // move start
            {
                start = mid + 1;
            }
        }

        return -1;
    }
};
// Find minimum in Sorted rotated array without Duplicates?How to find Max?
//  https://leetcode.com/submissions/detail/642426794/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        // define boundaries
        int start = 0;
        int end = n - 1;

        // |      /|
        // |     / |
        // |    /  |
        // | __/___|______ //cutt line
        // |  /    |  /
        // | /     | /
        // |_____________
        //   TTTT FF

        while (start < end) // condition
        {
            int mid = start - (start - end) / 2; // mid - because ans lies in end half

            // to decied in which half we are in - function : nums[m]>=num[0]
            if (nums[mid] >= nums[0]) // wrong half start-mid+1
            {
                start = mid + 1;
            }
            else // right half but shit to first false
            {
                end = mid;
            }
        }

        return nums[end] < nums[0] ? nums[end] : nums[0]; // sanity check
                                                          // we have to check if array is not rotated then ans is going to be nums[0]
    }
};

// Find Minmum in Sorted Rotated Array with Duplicates
//  https://leetcode.com/submissions/detail/642411470/
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = start - (start - end) / 2;
            if (nums[0] == nums[end]) // shrink end - (converting problem to problem wihout duplicates FFFTTT)
            {
                end--;
            }
            else if (nums[mid] >= nums[0]) // wrong half - move start to mid+1
            {
                start = mid + 1;
            }
            else // correct half - move end to mid (as we are in correct half so mid not mid-1)
            {
                end = mid;
            }
        }

        return nums[end] < nums[0] ? nums[end] : nums[0];
    }
};

// Search in Sorted Rotated Array
// https://leetcode.com/submissions/detail/642433081/
// Picture of Sorted ROtated is Important
int search(vector<int> &nums, int target)
{
    // nums is sorted

    int N = nums.size();

    // define boundaries
    int start = 0;
    int end = N - 1;

    while (start <= end) // condition start<=end because mid=(start+end)/2
    {
        int mid = (start + end) / 2;
        if (target == nums[mid]) // check if ans found
            return mid;
        else if (nums[mid] >= nums[start])                   // mid is in left half
            if (target >= nums[start] && nums[mid] > target) // we have to check if target is also in same half target>=nums[start] (using start)
                end = mid - 1;                               // if it is then if mid is greater than target then shift end
            else                                             // else shift start
                start = mid + 1;
        else                                               // mid is in right half
            if (target <= nums[end] && nums[mid] < target) // we have to check if target is also in same half   target<=nums[end] (using end)
                start = mid + 1;                           // if it is then if mid is less than target then shift start
            else                                           // else shift end
                end = mid - 1;
    }
    return -1;
}

// Search in Sorted Rotated - With Duplicates
// https://leetcode.com/submissions/detail/642435575/
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {

        // nums is sorted
        int N = nums.size();

        // define boundaries
        int start = 0;
        int end = N - 1;

        while (start <= end) // condition start<=end because mid=(start+end)/2
        {
            int mid = (start + end) / 2;
            if (target == nums[mid]) // check if ans found
                return 1;
            if (nums[end] == nums[0]) // Add Line if it contains Duplicate to convert to same as NON DUplicate one
                end--;
            else if (nums[mid] >= nums[start])                   // mid is in left half
                if (target >= nums[start] && nums[mid] > target) // we have to check if target is also in same half target>=nums[start] (using start)
                    end = mid - 1;                               // if it is then if mid is greater than target then shift end
                else                                             // else shift start
                    start = mid + 1;
            else                                               // mid is in right half
                if (target <= nums[end] && nums[mid] < target) // we have to check if target is also in same half   target<=nums[end] (using end)
                    start = mid + 1;                           // if it is then if mid is less than target then shift start
                else                                           // else shift end
                    end = mid - 1;
        }
        return 0;
    }
};

// First and last occurence of an element in sorted array
//  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//  https://leetcode.com/submissions/detail/642482569/
class Solution
{
public:
    int binary_search_f(int val, vector<int> &nums)
    {
        int n = nums.size();
        // define the boundaries
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            // search space is monotonic: idxes as well as array is sorted
            int mid = start - (start - end) / 2;
            if (nums[mid] < val) // TTTTFFFF - first false is our ans
            {
                start = mid + 1;
            }
            else // ans lies in false half - that is the end half ans lies
            {
                end = mid;
            }
        }

        return nums[end] == val ? end : -1;
    }
    int binary_search_l(int val, vector<int> &nums)
    {
        int n = nums.size();
        // define the boundaries
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            // search space is monotonic: idxes as well as array is sorted
            int mid = end - (end - start) / 2;
            if (nums[mid] <= val) // TTTTTTFFF - last true is going to be my ans
            {
                start = mid; // as we are in true half and ans is our last ture so move start to mid (as it can also be the ans)
            }
            else // ans lies in false half - that is the end half ans lies
            {
                end = mid - 1; // as we are in False half and ans is cannot lie here end to mid-1 (as it cannot  be the ans)
            }
        }

        return nums[start] == val ? start : -1;
    }

    vector<int> searchRange(vector<int> &nums, int val)
    {
        if (nums.size() == 0) // Mistake - Edge case missed
            return {-1, -1};
        return {binary_search_f(val, nums), binary_search_l(val, nums)};
    }
};

// Search in a nearly Sorted Array
// https://techiedelight.com/practice/?problem=SearchNearlySortedArray

// i ->i-1,i,i+1
class Solution
{
public:
    int findIndex(vector<int> const &nums, int target)
    {
        int n = nums.size();

        // define boundaries
        int start = 0;
        int end = n - 1;

        while (start <= end) // as half question
        {
            int mid = (start + end) / 2; // mid-as half question

            if (nums[mid] == target) // did we find our target?
                return mid;
            else if (mid - 1 >= 0 && target == nums[mid - 1]) // is left exist and if exist then is it equal to target
                return mid - 1;
            else if (mid + 1 < n && target == nums[mid + 1]) // is right exist and if exist then is it equal to target
                return mid + 1;
            else if (nums[mid] > target) // if any of the three elements are not equal to target
                                         // by comparing with mid - decide in which half to move
                                         // if nums[mid]> target  then move end=mid-2, As we are sure
                                         // that mid-1,mid,mid+1 are not target and
                                         // elements after mid-2 are not equal to target
                end = mid - 2;
            else
                start = mid + 2;
        }
        return -1;
    }
};

// Search in a Bitonic Array OR peak-index-in-a-mountain-array
// What is Bitonic Array?
// A sequence is bitonic if it monotonically increases and then monotonically decreases
// https://leetcode.com/submissions/detail/642510973/
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &nums)
    {

        int n = nums.size();

        // define boundaries
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = end - (end - start) / 2;

            if (nums[mid] > nums[mid - 1]) // Function is nums[m]>nums[m-1]
                                           // TTTFFF
                                           // ans is last true
                                           // s--m--e

            {
                start = mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        return start;
    }
};

// Similar to above-it will be same as we will choose one mountains and find its peak
// Find Peak element
//  https://leetcode.com/problems/find-peak-element/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        // define boundaries
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = end - (end - start) / 2;

            if (nums[mid] > nums[mid - 1]) // Function is nums[m]>nums[m-1]
                                           // TTTFFF
                                           // ans is last true
                                           // s--m--e

            {
                start = mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        return start;
    }
};

// Search An Element in Bitonic Array:
// Find Peak Element Application
// Then do binary search on each half

// Floor (e<=x) and Ceil (e>=x)
//  https://techiedelight.com/practice/?problem=FloorAndCeil
// Edge case missed-if size is zero
class Solution
{
public:
    int bs_floor(vector<int> &nums, int x)
    {
        // define boundaries
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = end - (end - start) / 2;
            // fuct:nums[m]<=x
            // TTTTFFF
            // ans is our last TRUE
            // TTTTFFF
            // s-m---e
            if (nums[mid] <= x)
            {
                start = mid;
            }
            else
            {
                end = mid - 1;
            }
        }

        return nums[start] <= x ? nums[start] : -1;
    }

    int bs_ceil(vector<int> &nums, int x)
    {
        // define boundaries
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = start - (start - end) / 2;
            // fuct:nums[m]>=x
            // FFFFTTTT
            // ans is our first TRUE
            // FFFFTTTT
            // s-m---e
            if (nums[mid] >= x)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return nums[end] >= x ? nums[end] : -1;
    }
    pair<int, int> findFloorAndCeil(vector<int> &nums, int x)
    {
        if (nums.size() == 0)
            return {-1, -1};
        // Write your code here...
        return {bs_floor(nums, x), bs_ceil(nums, x)};
    }
};

// 15 Minimum Difference Element in a Sorted Array for given key
// https://www.youtube.com/watch?v=3RhGdmoF_ac&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=15
// Application of prev ques:  find floor & ceil of the given element and return one of them which has min diff with the given key

// Next Greater Letter
//  https://leetcode.com/problems/find-smallest-letter-greater-than-target/
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        // Sorted given:SO Binary Search
        int n = letters.size();
        // defining the search space
        int start = 0;
        int end = n - 1;
        if (target >= letters[n - 1])
            return letters[0];
        while (start < end) // B.S
        {
            int mid = start - (start - end) / 2;

            // Func: nums[mid]>target
            // FFFFTTT
            // ans is first true -because smallest is asked
            // FFFFTTT
            // s--m--e

            if (letters[mid] > target)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return letters[end] > target ? letters[end] : letters[0]; // sanity check : what if all are FFFFFF
    }
};

// How to manually find the search space for ans
