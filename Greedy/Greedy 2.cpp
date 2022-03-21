

//Maximum product subset:https:
// practice.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1/
// If there are only zeros //zerocount==n, 

// If there are even number of negative numbers and no zeros, result is simply product of all

// If there are odd number of negative numbers and no zeros, result is product of all except the negative integer with the least absolute value.

    // If there is  atleast one zero and  sigle negative  and nopositive//return 0
    //else =product/max_abs(negval)
  
int maxProductSubset(int a[], int n)
{
    if (n == 1)
        return a[0];
 
    // Find count of negative numbers, count
    // of zeros, negative number
    // with least absolute value
    // and product of non-zero numbers
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count_zero++;
            continue;
        }
        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
 
        prod = prod * a[i];
    }
 
    // If there are all zeros
    if (count_zero == n)
        return 0;
 
    // If there are odd number of
    // negative numbers
    if (count_neg & 1) {
 
        // Exceptional case: There is only
        // negative and all other are zeros
        if (count_neg == 1 &&
            count_zero > 0 &&
            count_zero + count_neg == n)
            return 0;
 
        // Otherwise result is product of
        // all non-zeros divided by
        //negative number with
        // least absolute value
        prod = prod / max_neg;
    }
 
    return prod;
}                       

//Maximum sum after K negations (-arr[i])
// https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1/#
   int maximizeSum(self, a, n, k){
       int a=sort(a.begin(),a.end());
       int i=0;
       int count=0;
       while( i<k and i<n){
           if(a[i]<0){
               count+=1
               a[i]*=-1
               i+=1
           }else{
               break;
           }
        }
       if ((k-count)%2==0)
           return(accumulate(a.begin(),a.end()));
       else{
           sort(a)
           a[0]*=-1
           return(sum(a))
       }
   }

// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1/
class Solution{
public:
    int minimumDays(int S, int N, int M){
       int daysClose = S / 7;
       int daysAvail = S - daysClose;
       int x = S*M; // total food req to survive S days
       int daysSufficient = x % N == 0 ? x/N : x/N + 1; // HOw may days i should buy?
       if(daysSufficient <= daysAvail) return daysSuff;
       return (-1);
    }
};


// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1/#


//Thinking greedily : taking minimum amount candies and getting free max amount candy
int findMinimum(int arr[], int n, int k)
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        // Buy current candy
        res += arr[i];

        n = n - k;
    }
    return res;
}

// Function to find the maximum amount
// to buy all candies
int findMaximum(int arr[], int n, int k)
{
    int res = 0, start = 0;

    for (int i = n - 1; i >= start; i--) 
    {
        // Buy candy with maximum amount
        res += arr[i];

        // And get k candies for free from
        // the starting
        start += k;
    }
    return res;
}
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        return {findMinimum(candies,N,K),findMaximum(candies,N,K)};
    }

//Find smallest D digit no. with S sum
string smallestNumber(int S, int D){
    string str(D, '0');
    if (9 * D < S) return "-1";
    str[0] = '1';
    S -= 1;
    int i;
    for (i = D - 1;i>=0; i--) {
        if (S > 9) {
            str[i] = '9';
            S -= 9;
        }
        else {
            str[i] = S + '0';
            if(i==0) str[i]++;
            break;
        }
    }
    return str;
        
    }


// https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/

//Idea is to make an array with maximum and minimum alternating :)