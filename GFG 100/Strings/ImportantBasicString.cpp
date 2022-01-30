#include <bits/stdc++.h>

using namespace std;

//Q1 Sort a string in O(N) time

//Q2 Permutation of a string or Anagrams

//Q3 Permutation in a string (+sliding window)

//Q4 Unique charaters present?

//Q5 Longest Unique character substring
//->Follow Up it minimum window substring

//Q6 Check String Rotation

//Q7 String Compression

//Q8 Remove all occurences of String

//Count Sort
void sortString(string &s)
{
    vector<int> fmp(26, 0);

    //make frequency map of s
    for (auto e : s)
        fmp[e - 'a']++;

    int j = 0;

    for (int i = 0; i < 26; i++)
    {
        //replace one by one with the known frequncy in sorted order
        while (fmp[i]--)
        {
            s[j++] = 'a' + i;
        }
    }
}

// https://leetcode.com/problems/valid-anagram/

bool isAnagram(string s, string t)
{
    vector<int> fmp(26, 0);

    for (auto e : s)
        fmp[e - 'a']++;

    for (auto e : t)
        fmp[e - 'a']--;

    for (int i = 0; i < 26; i++)
        if (fmp[i] != 0)
            return 0;

    return 1;
}

// https://leetcode.com/problems/permutation-in-string/
bool checkInclusion(string s1, string s2)
{

    //base case
    if (s1.size() > s2.size())
        return 0;

    vector<int> fmp1(26, 0); //freqency map for s1
    vector<int> fmp2(26, 0); //freqency map for s2

    for (auto e : s1)
        fmp1[e - 'a']++;

    //for window of size s1 as we have to check  if s2 contains a permutation of s1

    for (int i = 0; i < s1.size(); i++)
        fmp2[s2[i] - 'a']++;

    if (fmp1 == fmp2)
        return 1;

    //slide window
    int j = s1.size();
    int prev = 0;
    while (j < s2.size())
    {
        fmp2[s2[prev] - 'a']--;
        fmp2[s2[j] - 'a']++;
        if (fmp1 == fmp2)
            return 1;
        j++, prev++;
    }
    return 0;
}

// https://www.geeksforgeeks.org/determine-string-unique-characters/
bool uniqueCharacters(string str)
{

    int checker = 0; //first 26 bit for a-z

    for (int i = 0; i < str.length(); i++)
    {

        int bitAtIndex = str[i] - 'a';

        // if that bit is already set in
        // checker, return false
        if ((checker & (1 << bitAtIndex)) > 0)
        {
            return false;
        }

        // otherwise update and continue by
        // setting that bit in the checker
        checker = checker | (1 << bitAtIndex);
    }

    // no duplicates encountered, return true
    return true;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(string s)
{

    vector<int> lastSeen(256, -1); //Initializing with -1

    int ans = 0;

    int j = -1; //This is for Tracking last seen for all prev characters

    for (int i = 0; i < s.size(); i++)
    {
        j = max(j, lastSeen[s[i]]); //maximizing with Last seen for current character

        ans = max(ans, i - j); //maximizing the length

        lastSeen[s[i]] = i; //Updating last seen
    }

    return ans;
}

//https://leetcode.com/problems/rotate-string/
bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return 0;

    goal += goal;
    if (goal.find(s) != string::npos)
        return 1;
    return 0;
}

//compression of String
// https://leetcode.com/problems/string-compression/
int compress(vector<char> &chars)
{

    //As the size always is same or reduces so we do not need to form string

    int i = 0;     // current index
    int index = 0; // solution index

    while (i < chars.size())
    {
        char current = chars[i];
        int count = 1;

        while (i++ < chars.size() && chars[i] == current)
            count++;

        chars[index++] = current;

        if (count > 1) //if count ==1 then we do not need its frequency appended given in ques
        {
            for (char &ch : to_string(count)) //splitting number to character array
                chars[index++] = ch;
        }
    }

    return index;
}
int main()
{
    string s = "zpeap";
    sortString(s);
    cout << s;
}