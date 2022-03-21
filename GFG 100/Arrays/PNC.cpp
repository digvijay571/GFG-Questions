
// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
// N time pick and deliver you can after  u pick
// P1 ....D1
// Count total ways of delivery

class Solution
{
public:
    int countOrders(int n)
    {
        int m = 1e9 + 7;
        ll slots = 2 * n;
        ll total_ways = 1;

        while (slots > 0)
        {
            total_ways = (total_ways % m * ((slots * (slots - 1)) / 2) % m) % m; // NC2
            slots -= 2;                                                          // as we have occupied two slots
        }
        return total_ways % m;
    }

}
// Given a string S containing lowercase english alphabet characters.
// The task is to calculate the number of distinct strings that can be obtained after performing exactly one swap.
// https://practice.geeksforgeeks.org/problems/2ac2f925b836b0625d848a0539ffd3d2d2995f92/1#
#define ll long long

long long
countStrings(string S)
{

    /*
    Formular for n distinct charater ( n * (n-1) )/ 2
    */
    long long res = (S.size() * (S.size() - 1)) / 2;
    long long arr[26] = {0};
    for (char i : S)
        arr[i - 'a']++;
    int removed = false;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 1)
        {
            // Remove the count of repeating strings
            res = res - (arr[i] * (arr[i] - 1)) / 2;
            removed = true;
        }
    }
    // +1 for the repeated strings
    return removed == false ? res : res + 1; // as we have removed the original string once
}


// Concatenate two numbers

// calculate freqency of each val
// since we have two values

// we can partition the given string and
// check its frequencies
// and calculate the pairs possible to form it

// Idea:

// if n members can form a pair with other m member
// total ways of making a pair is m*n

// but if the nos are same then
// it is same as n *(n-1)

class Solution
{
public:
long long countPairs(int N, int X, vector<int> numbers)
{
    // code here
    string s = to_string(X);
    map<string, int> m;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        m[to_string(numbers[i])]++;
    }
    for (int i = 1; i < s.length(); i++)
    {
        string s1 = s.substr(0, i); // 0 to i-1
        string s2 = s.substr(i);    // i to n-1

        if (s1 == s2) // equal
            ans = ans + (m[s1] * (m[s1] - 1));
        else // not equal
            ans = ans + m[s1] * m[s2];
    }
    return ans;
}
};