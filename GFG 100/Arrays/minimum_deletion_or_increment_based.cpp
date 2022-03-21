// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/discuss/927654/C%2B%2BJavaPython3-Simple-time-O(n)-space-O(1)-a-small-array-is-all-you-need
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/discuss/1453366/Java-O(N)-similar-to-1665
// After step 1, the problem becomes similar to this one: https://leetcode.com/problems/minimum-increment-to-make-array-unique/



// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
 // Incrementing all but one is equivalent to decrementing that one. So let's do that instead. How many single-element decrements to make all equal? No point to decrementing below the current minimum, so how many single-element decrements to make all equal to the current minimum? Just take the difference from what we currently have (the sum) to what we want (n times the minimum).
        
        
        //Brute force
        //select one max and increment others untill elements are not equal
        
        int MIN=*min_element(nums.begin(),nums.end());

        //Optimised is select max and decrement it
        //Best explanation:
        //https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/299009/Java-easy-with-detailed-explanation...
        
        
        //minimum value will remain minimum untill end
        //so it will be incremented always
        //the let the minimum val be increment by k to get the final elements of array x
        
        
        //so min+k = x
        
        //sum intial be si
        
        //sum after the increament will be
        //si+(n-1 elements are incremented by k)
        
        //si+(n-1)k = x*n
        //si+(n-1)k = (min+k)*n
        //si+nk-k=min*n+k*n
        //k= si-min*n
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        int ans=0;
        for(auto num:nums)
        {
            ans += num-MIN;
        }
        return ans;
    }
};