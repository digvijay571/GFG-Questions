

// Hash maps are generally of  types
// int,val
// int,idx
// int,counter
// int,vector<int>
// sortedString,strings
// char,idx
// pair<type,type>,val

// map can be considered as with defaut values like 0,{}
// mp[key]++;//is valid if key is not present : default val is taken as 0
// mp[key].push_back(val);//is valid if key is not present : default val is taken as {}

// How to insert?
// mp[key] = val;
// mp.insert({key,val});

// How to access?
// mp[key] //key gets inserted

//find count begin end
//erase size

//How to iteratie?
//for(auto e:map)
// {
    //e ->all the entries in map
    //e.first ->key
    //e.second->value
// }

// or correspondece can also be stored in hash map with unique key

// LOGIC:When ever pair comes think of two some ones

// Q.Two Sum -Using HashMap
// if we have to return the index then we cannot sort
// let current element be y ,let x be a prev element->  if 60-y == x  x+y==60
// It is some what similar to taking same variable to one side in a eqation
vector<int> twoSum(vector<int> &nums, int target)
{

    unordered_map<int, int> mp; //<val,idx>

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.count(target - nums[i]) == 1)
        {
            return {i, mp[target - nums[i]]};
        }

        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// k DIFF pAIRS
//  Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array.
//   Here a k-diff pair is defined as an integer pair (i, j),
//  where i and j are both numbers in the array and their absolute difference is k.
public
int findPairs(int[] nums, int k)
{
    if (nums == null || nums.length == 0 || k < 0)
        return 0;

    Map<Integer, Integer> map = new HashMap<>();
    int count = 0;
    for (int i : nums)
    {
        map.put(i, map.getOrDefault(i, 0) + 1);
    }

    for (Map.Entry<Integer, Integer> entry : map.entrySet())
    {
        if (k == 0)
        {
            // count how many elements in the array that appear more than twice.
            if (entry.getValue() >= 2)
            {
                count++;
            }
        }
        else
        {
            if (map.containsKey(entry.getKey() + k))
            {
                count++;
            }
        }
    }

    // Two sum closest
    // ThreeSum
    // FourSum
    // Valid triangle

    //  two pointers approach. Let us choose first index i.
    //  Then we need to find number of pairs (left, right) where left < right < i and a_{left} + a_{right} > a_i.
    //  Let us start with left = 1 and right = i-1. Then we can use Two Pointers
    //  approach to find number of desired pairs inO(n) for fixed i. Note, that it is very similar to all 2Sum or 3Sum problems.
    //  Important thing to keep in mind is that array is sorted.

    //  When we meet the valid triangle condition (nums[left] + nums[right] > nums[i]) we know we have found a triangle.
    //  Now if you see as we move forward from left to right the nums[left] is gonna increase.
    //  So we know all the elements from left index to right index will satisfy the valid triangle condition.
    //  We need to record that and that's why he used count += right - left, to record all the elements from left to right.

 class Solution:
    def triangleNumber(self, nums):
        nums, count, n = sorted(nums), 0, len(nums)
        for i in range(2, n):
            left, right = 0, i-1
            while left < right:
                if nums[left] + nums[right] > nums[i]:
                    count += (right - left)
                    right -= 1
                else:
                    left += 1
        return count


//Two sum variaion:
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/1662885/c%2B%2B-oror-hashmaps-oror-explaination
int numPairsDivisibleBy60(vector<int> &time)
 {
     // similar to question - find no of pairs (a,b) such that a+b=k
     // store all numbers in hashmap then find count+=map[k-nums[i]]
     // for each nums[i]
     // similarly
     // here in this question
     // store remainders
     // sum of remainders must be 60(=k)
     // for ex= 20%60=20, so another number of remainder 40 is required
     // 100%60=40 is required
     // do a dry run of this program by yourself
     int res = 0;
     unordered_map<int, int> remainders;
     for (int i = 0; i < time.size(); i++)
     {
         if (time[i] % 60 == 0)
         {
             res += remainders[0];
         }
         else
         {
             res += remainders[60 - time[i] % 60];
         }
         remainders[time[i] % 60]++;
     }
     return res;
 }

 // SubArray Sum:

 // Sum-Count Map
 // Vector of i,j can also be made
 // Or we can compute Sub Array Sum using Prefix sum
 //  Go through all subarrays, compute sums
 //  and count occurrences of sums.
 unordered_map<int, int>
     m;
 for (int i = 0; i < n; i++)
 {
     int sum = 0;
     for (int j = i; j < n; j++)
     {
         sum += arr[j];
         m[sum]++;
     }
 }

 // Q.Sum of All SubArrays
 //  If we take a close look then we observe a pattern. Let take an example

 // arr[] = [1, 2, 3], n = 3
 // All subarrays :  [1], [1, 2], [1, 2, 3],
 //                  [2], [2, 3], [3]
 // here first element 'arr[0]' appears 3 times
 //      second element 'arr[1]' appears 4 times
 //      third element 'arr[2]' appears 3 times

 // Every element arr[i] appears in two types of subsets:
 // i)  In subarrays beginning with arr[i]. There are
 //     (n-i) such subsets. For example [2] appears
 //     in [2] and [2, 3].
 // ii) In (n-i)*i subarrays where this element is not
 //     first element. For example [2] appears in
 //     [1, 2] and [1, 2, 3].

 // OR : THere are i+1 choices for start of that subarray ->0 to i
 //      and there are n-i choices for end of subarray i->n-1 i.e. n-1 - i +1 = n-i
 //      So count of subarrays containing element = (i+1)*(n-i)

 // Idea:it to find count of each element - How many subarrays will it appear add it to ans
 long int SubArraySum(int arr[], int n)
 {
     long int result = 0;

     // computing sum of subarray using formula
     for (int i = 0; i < n; i++)
         result += (arr[i] * (i + 1) * (n - i));

     // return all subarray sum
     return result;
 }

 // Prfix SUm:prefix[i] = sum of all prev elments +current element

 // How to find subarray sum using prefix sum
 // Let Array elements be  a,b,c,d,e
 // idx:0 1 2 3 4

 // sumArraySum[3,4] = prefixSum[4]-prefixSum[2];

 // Another Observation Based Question

 // Q.find odd sum subArrays
 // As we know that : odd+odd = even , even+even=even (same is even)
 //                   even+odd=odd

 // so even-odd = odd and odd-even=odd

 // i.e.
 // even prefix sums mei se odd hata dege to odd sum subarray milega
 // odd prefix sum mei se even prefix sums hata dege to odd sum subarray milega +1(for current odd subarray form start)

 // LOGIC:when a word subarray sum + target comes - think of prefix sum hashmap

 // Q.Find if there exist a subarray with zero sum
 // let current sum be y ,let x be a prev sum->  if y == x  it means sum after x till y is zero

 // https://www.techiedelight.com/check-subarray-with-0-sum-exists-not/
 // THe idea is to all prev  prefix sums ending at every index in a map <key,val>=<sum,index>
 // calculate current prefix sum
 // and if currentsum==prevsum that means there is atleast one subarray ending at current index and starting after the index where prev sum was found
 // the sum must be zero
 // sum ......sum
 //+0   =sum
 // j  j+1....i
 // sum[j+1...i]==0
 // /if current sum is 10 (index 10)and {1,4,8} are the indexes where we found the sum(10) before
 // so subarrays with zero sum are [2,10] [5,10] [9,10]

 // Q.find all subarray with zero sum //same idea as above

 // LINK:https://www.techiedelight.com/find-sub-array-with-0-sum/

 set<vector<int>> getAllZeroSumSubarrays(vector<int> const &nums)
 {
     set<vector<int>> subarrays;

     unordered_map<int, vector<int>> mp; //<prefixsum,vector of indexes>

     int n = nums.size();
     int prefixsum = 0;

     for (int i = 0; i < n; i++)
     {

         prefixsum += nums[i];

         // IMP:target check for handling subarrays starting form index 0
         if (prefixsum == 0)
         {
             vector<int> ans(nums.begin(), nums.begin() + i + 1);
             subarrays.insert(ans);
         }

         // previours occurence check
         if (mp.count(prefixsum))
         {
             vector<int> previndexes = mp[prefixsum];

             for (auto previndex : previndexes)
             {
                 vector<int> ans(nums.begin() + previndex + 1, nums.begin() + i + 1);
                 subarrays.insert(ans);
             }
         }

         mp[prefixsum].push_back(i); // mistake was i was putting this statement inside a else
     }

     return subarrays;
 }

 // Qfind all subarray with k sum
 //      i i+1                   j
 //...sum ....................currsum
 // sum==currsum-target    //Exist[currsum-target]

 // It means the sum after i till currsum is equal to target

 // when binary array come - 0 can be replaced by -1 for contrubution
 // Find Subarrays with equal 0s and 1s: can be reformed to
 // Find Subarrays with 0 sum
 // we will contribute -1 for each 0 in array

 // Some Other Concept:
 // If we use hashmap for storing charater count: its size will give distinct no. of characters
 // Sum of Ascii values is also a concept

 // Hint: This situation is similar to a situation where we need to count the number of handshakes between n people.
 // As Person A can't shake his own hand and Person A giving handshake to Person B is equal to Person B giving handshake to Person A the number of handshakes are n*(n-1)/2.
 // A good pair is something that is obtained by seeing number of handshakes between equal elements.

//  Given an array of integers nums, return the number of good pairs.

//A pair(i, j)
//  is called good if nums[i] == nums[j] and i < j.

class Solution
 {
 public:
     int numIdenticalPairs(vector<int> &nums)
     {
         unordered_map<int, int> fmp;

         for (auto num : nums)
             fmp[num]++;

         int count = 0;
         for (auto p : fmp)
         {
             int freq = p.second;

             count += freq * (freq - 1) / 2; // Pair of 2 is given by nC2;
         }
         return count;
     }
 };

 // same group mei pair select karna hai :)
