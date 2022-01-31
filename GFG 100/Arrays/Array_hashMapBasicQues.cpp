

//Q.Two Sum -Using HashMap
//if we have to return the index then we cannot sort
//so we check at every index wheater
 vector<int> twoSum(vector<int>& nums, int target) 
    {
        
        unordered_map<int,int> mp;//<val,idx>
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(target-nums[i])==1)
            {
                return {i,mp[target-nums[i]]};
            }
            
            mp[nums[i]]=i;
        }
      return  {-1,-1};
}

//Two sum variaion:
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/1662885/c%2B%2B-oror-hashmaps-oror-explaination
  int numPairsDivisibleBy60(vector<int>& time) {
        //similar to question - find no of pairs (a,b) such that a+b=k
        //store all numbers in hashmap then find count+=map[k-nums[i]]
        //for each nums[i]
        //similarly
        //here in this question
        //store remainders
        //sum of remainders must be 60(=k)
        //for ex= 20%60=20, so another number of remainder 40 is required
        //100%60=40 is required
        //do a dry run of this program by yourself
        int res=0;
        unordered_map<int,int> remainders;
        for(int i=0;i<time.size();i++){
            if(time[i]%60==0){
                res+=remainders[0];
            }else{
                res+=remainders[60-time[i]%60];
            }
            remainders[time[i]%60]++;
        }
        return res;
        
        
        
    }


//Q.Find if there exist a subarray with zero sum
// https://www.techiedelight.com/check-subarray-with-0-sum-exists-not/
//THe idea is to all prev  prefix sums ending at every index in a map <key,val>=<sum,index>
//calculate current prefix sum
//and if currentsum==prevsum that means there is atleast one subarray ending at current index and starting after the index where prev sum was found
//the sum must be zero
//sum ......sum
//+0   =sum
//j  j+1....i
//sum[j+1...i]==0
// /if current sum is 10 (index 10)and {1,4,8} are the indexes where we found the sum(10) before
//so subarrays with zero sum are [2,10] [5,10] [9,10]




//Q.find all subarray with zero sum //same idea as above

// LINK:https://www.techiedelight.com/find-sub-array-with-0-sum/




//Qfind all subarray with k sum
//     i i+1                   j
//...sum ....................currsum
//sum==currsum-target    //Exist[currsum-target]

//It means the sum after i till currsum is equal to target
