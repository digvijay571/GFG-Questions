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
