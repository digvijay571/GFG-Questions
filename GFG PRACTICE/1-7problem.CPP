
// Q1 https://practice.geeksforgeeks.org/problems/k-pangrams0909/1/
// Concept: BIT CHAR MAP
bool kPangram(string str, int k)
{

    int mark = 0; // 25.....0
                  // z......a

    //   ith bit      1<<1;              1<<0;
    // 1<<(c-'a');    1<<('b'-'a');      1<<('a'-'a');
    // each bit has marking of existence of a
    int count = 0;
    for (auto c : str)
    {
        if (c == ' ')
        {
            count++;
            continue;
        }

        mark = mark | (1 << (c - 'a')); // if c is present mark using mark = mark | (1 << (c-'a');
    }

    if ((str.size() - count) < 26)
        return 0;

    count = 0;

    // iterating through 26 bits
    for (int i = 1; i <= 26; i++)
    {

        count += !(mark & 1) ? 1 : 0; // if not set is means not present in sring

        mark = mark >> 1;
    }

    return count <= k;
}

// Q2: https://practice.geeksforgeeks.org/problems/minimum-indexed-character0221/1/

// Concept:INDEX MAP vector:  vector<int> idxMap(26,-1);
// MIN INDEX MAP
// MAX INDEX MAP
// vector<int> INDEX MAP

string printMinIndexChar(string S, string patt)
{
    vector<int> idxMap(26, -1); // marking all char not present so idx=-1

    for (int i = 0; i < S.size(); i++)
    {
        if (idxMap[S[i] - 'a'] == -1)
            idxMap[S[i] - 'a'] = i;
    }

    int ans = INT_MAX;

    for (auto c : patt)
    {
        int idx = idxMap[c - 'a'];
        if (idx != -1)
        {
            ans = min(ans, idx);
        }
    }

    if (ans == INT_MAX)
        return "$";

    string s(1, S[ans]);
    //  cout<<s<<endl;
    return s;
}

// Q3 Concept:Two SUm Extension
//   https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// ALgo:
// SOrt the arrary

// get a loop for arr[i] 0..n-2
// get the target = sum-arr[i]

// Reduced to Two sum

class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int nums[], int n, int X)
    {
        sort(nums, nums + n);

        // arr[i]+arr[j]+arr[k]==X
        for (int i = 0; i < n - 2; i++) // for choosing arr[i] : remember n-2 as we do not want runtime error...
        {
            int target = X - nums[i];
            int l = i + 1;
            int h = n - 1;

            while (l < h)
            {
                if (nums[l] + nums[h] == target)
                {
                    return 1;
                }
                else if (nums[l] + nums[h] > target) // decrease high
                {
                    h--;
                }
                else // if(nums[l]+nums[h]<target)//increase low
                {
                    l++;
                }
            }
        }
        return 0;
    }
};

// Q4 Concept:Prefix and Postfix Sum:
// My approach
//  https://practice.geeksforgeeks.org/problems/equal-sum0810/1/

class Solution
{
public:
    string equilibrium(int *arr, int n)
    {
        vector<int> prefix(n, 0), postfix(n, 0);

        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        postfix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            postfix[i] = postfix[i + 1] + arr[i];
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (prefix[i] == postfix[i])
                return "YES";
        }
        return "NO";
    }
};

// Best Approach : Using total sum and calculating left and right sum on go

int equilibrium(int arr[], int n)
{
    int sum = 0;     // initialize sum of whole array
    int leftsum = 0; // initialize leftsum

    /* Find sum of the whole array */
    for (int i = 0; i < n; ++i)
        sum += arr[i];

    for (int i = 0; i < n; ++i)
    {
        sum -= arr[i]; // sum is now right sum for index i

        if (leftsum == sum)
            return i;

        leftsum += arr[i];
    }

    /* If no equilibrium index found, then return 0 */
    return -1;
}

// Q5 Check Isogram... string which have unique charachters

// BitMap:26 bits for each character

class Solution
{
public:
    // Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        int marker = 0; // FFFFFFFFFFFFFF ->any character not found

        for (auto c : s)
        {
            int bitidx = c - 'a';

            int mask = (1 << bitidx);

            int isset = marker & mask; // check if bit is alredy set
                                       // already found the character
            if (isset)
            {
                return false;
            }
            else
            {
                marker = marker | mask; // mark that it is found
                                        // it is going to set the bit at that idx
            }
        }

        return true;
    }
};

// Q6

// https://practice.geeksforgeeks.org/problems/minimum-steps-to-make-product-equal-to-one/0/#

int makeProductOne(int arr[], int N)
{
    // The tricky part is to handele negative elements and zeros

    int zerocount = 0;

    int negcount = 0;

    int steps = 0;
    for (int i = 0; i < N; i++)
    {
        int e = arr[i];

        if (e == 0)
            zerocount++;
        else if (e > 0)
            steps += e - 1;
        else
        {
            negcount += 1;
            steps += (-e - 1);
        }
    }

    steps += zerocount;

    if (negcount % 2 != 0 && zerocount == 0)
        steps += 2;

    return steps;
}

// The algo is:
// Product will be one when all elements are one:)

// If element is positive we will covert it to one
// steps = e-1;

// zero should covert to -1 or 1 it depends
// steps+=zeros;

// negative elements will be coverted to -1
// steps +=-e-1;

// But in case :
// if there are no zeros and odd negative elements then one negative element must be coverted to 1
// steps=steps+2;

// if a element is zero and we have odd number of negative elements then all negative elements will
// be converted to -1 and a zero will be converted to -1



// Q7 Rearrange an array so that nums[i]=nums[nums[i]]
//without using extra space


//How to swap two nos ...do not use any extra space:

// a <--> b
//Idea is to store sum in one variable:

// a=a+b;
// b=a-b; // a+b-b=a
// a = a-b;//a+b-a=b


// similar to above idea :

//we can store:
//nums[i] = nums[i]+nums[nums[i] % n]*n;

//then divide whole array by n

//nums[i] = nums[i]/n+nums[nums[i]];

//As 0<nums[i]<n-1 as for valid index so ...nums[i]/n==0
//nums[i] = nums[nums[i]] 

//Hence Done:)

 void arrange(long long arr[], int n) {
        
        
        for(int i=0;i<n;i++)//using indexing or ipointer we are scanning array .. for n size array idx 0..n-1
        {
            arr[i] +=(arr[arr[i]]%n)*n;
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i] =arr[i]/n;
        }
        
    }