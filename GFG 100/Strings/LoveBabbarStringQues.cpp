// 0	Reverse a String

void reverse(string &s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = char;
        i++, j--;
    }
}

//1 Check whether a String is Palindrome or not

bool palindrome(string &s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return 0;
        i++, j--;
    }
    return 1;
}

//2 Find Duplicate characters in a string

//we can use array of 256 chars //A and a are diffrent or
// unorderedmap<char,int>//orderis not maintained while accessing
//fmp-frequency of all characters present in the string -print whoever is greater than 1

void printDuplicates(string &s)
{
    unordered_map<char, int> fmp;

    for (auto c : s)
        fmp[c]++;

    for (auto p : fmp)
    {
        if (p.second > 1)
            cout << p.first;
    }
}

//3 Write a Code to check whether one string is a rotation of another
//idea is to concatenate two time the rotated string and find the original in it
//find is implemented using kmp
// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

//4 To check shuffle
//Idea is :
//First thing the length should be same
//second
//1:shuffle strings have same sorted string
//2:shuffle strings have same frequency map


//5 CountAndSay


class Solution {
public:
    
    string cAS(int n)
    {
        if(n==1) return "1";
        
        //recursively call for ans pf smaller subproblem
        string s = cAS(n-1);
        

        //calculating ans for current problem using prev ans
        //CountAndSay Code for a string 

        int i=0;
        string ans="";
        while(i<s.size())
        {
            char currChar=s[i];
            int count=1;

            while(++i < s.size() && s[i]==currChar ) count++;
            
            ans +=to_string(count);
            ans +=currChar;
        }
        
        return ans;
    }
    string countAndSay(int n) {
        return cAS(n);
    }
};

//Count no. of permutions which can be obtained by exactly one swap.
// https://practice.geeksforgeeks.org/problems/2ac2f925b836b0625d848a0539ffd3d2d2995f92/1#
long long countStrings(string S)
    {
   
        /* 
        Formular for n distinct charater ( n * (n-1) )/ 2
        */
        long long res = (S.size() * (S.size() - 1))/2;
        long long fmp[26] = {0};
        for(char c : S)
            fmp[c -'a']++;
        int removed = false;
        for(int i = 0; i< 26; i++)
        {
            if(fmp[i] > 1)
            {   
                //Remove the count of repeating strings 
                res = res - (fmp[i] * (fmp[i] - 1))/2;
                removed=true;
            }
        }
        // +1 for the repeated strings 
        return removed == false ? res : res+1;//as we have removed the original string in which all were in same order as original string
      
        
    }