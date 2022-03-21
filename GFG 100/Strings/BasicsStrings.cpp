#include <bits/stdc++.h>

using namespace std;

//String is Array of characters
//https://leetcode.com/problems/reverse-string/

string reverse(string str)
{
    int s = 0;
    int e = str.size() - 1;

    while (s < e)
    {
        char temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s++, e--;
    }

    return str;
}

//Palindrome is a string which read same backward and forward

bool isPalindrome(string str)
{
    int s = 0;
    int e = str.size() - 1;

    while (s < e)
    {
        if (str[s++] != str[e--])
            return false;
    }
    return true;
}

//recursive
bool isPalindrome(int s, int e, string str)
{
    if (s == e)
        return 1;

    if (str[s] != str[e])
        return 0;

    return isPalindrome(s + 1, e - 1, str);
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
bool isUpperCase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool isLowerCase(char c)
{
    return (c >= 'a' && c <= 'z');
}

bool isAlpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;

    return false;
}

// https://leetcode.com/problems/valid-palindrome/

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool isAlpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;

    return false;
}

//65-'A' - 97 -'a'  ->diff 32
void toggleCase(char &c)
{
    c ^= 32;
}

class Solution
{
public:
    bool isPalindrome(string str)
    {

        int s = 0;
        int e = str.size() - 1;

        while (s < e)
        {
            while (s < e && !(isDigit(str[s]) || isAlpha(str[s]))) //when u are accessing index make sure it is valid
                s++;
            while (s < e && !(isDigit(str[e]) || isAlpha(str[e])))
                e--;

            if (s < e && tolower(str[s]) != tolower(str[e])) //palindromic check
            {
                return false;
            }

            s++;
            e--;
        }

        return true;
    }
};

//Maximum Occuring Character
//Concept:Frequency Map
//There are a total of 256 characters in a string

vector<int> frequencyMap(string s)
{

    int n = s.size();

    vector<int> fmp(256, 0); //frequency map of each character here capital and small letters are considered diffrent

    for (int i = 0; i < n; i++)
    {
        fmp[s[i] - 'a']++;
    }

    return fmp;
}

//frequency map -2

//s[i]-'a' and s[i]-'A'
//0 1 2 3 4 5 6 7..................................25

//'a'+i :IMP
//a b c d e f g h i j k l m n o p q r s t u v w x y z

vector<int> frequencyMap(string s)
{

    int n = s.size();

    vector<int> fmp(26, 0); //frequency map of each character here capital and small letters are considered same

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            fmp[s[i] - 'a']++;

        if (s[i] >= 'A' && s[i] <= 'Z')
            fmp[s[i] - 'A']++;
    }

    return fmp;
}

char findMaxOccuring(string s)
{
    vector<int> fmp = frequencyMap(s);

    return (char)(max_element(fmp.begin(), fmp.end()) - fmp.begin() + 'a'); //typeCasting because when we add they are converted in AsCii values
}










//Concept:Bit Marker  for each character
https://practice.geeksforgeeks.org/problems/k-pangrams0909/1/
bool kPangram(string str, int k)
{

    int mark=0;//25.....0
               //z......a
               
               //   ith bit      1<<1;              1<<0;
               // 1<<(c-'a');    1<<('b'-'a');      1<<('a'-'a');
               //each bit has marking of existence of a 
    int count=0;
    for(auto c:str)
    {
        if(c==' '){ 
        count++;
        continue;
        }
        
        mark = mark | (1 << (c-'a'));//if c is present mark using mark = mark | (1 << (c-'a');
    }

    if((str.size()- count)<26)return 0;
    
    count=0;
    
    //iterating through 26 bits
    for(int i=1;i<=26;i++)
    {
        
       count += !(mark&1)?1:0;//if not set is means not present in sring

       mark=mark>>1;
    }
    
   return  count<=k;
}


// Check Isogram... string which have unique charachters

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

            int mask = (1 << bitidx);//2^i can also be used to make mask

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


//Index Map

//Q.LeftMost Non-Repeating Character-Idea is to store the first ocurrence in frequecy map and if it appears again then mark it with -2  and then minimize the indexes >=0

//Q.LeftMost Repeating Character-Idea is to store the first ocurrence index in frequecy map and if it appears again then skip it ( not -1) then minimize the indexes >=0


//Ranking Based

//Q.Lexiographic Rank:Idea to to find strings which are lexiographically smaller than current string and then add 1 to get rank of current string

//Q.next Lexiographical string-nextPermutation in strings

//Q. Print all permutations in sorted (lexicographic) order


//Q.https://www.geeksforgeeks.org/length-of-longest-common-subsequence-containing-vowels












// The first cin>>a; reads a single word, skipping over any leading space characters,
//  and stopping when it encounters a space character (which includes the end of the line).


//cin.get()
// The cin.get() after every initialization is there to "grab"
//  the newline character that gets put in the stream every time you press enter.
//   Say you start entering your values like this:

// 2 

// a b c d...
// Assuming you have pressed enter after 2, 
// the newline character was also put on the stream.
//  When you call cin.get() after that, it will grab and discard the newline character, 
//  allowing the rest of your code to properly get the input.

// cin.get ( char* s, streamsize n, char delim ); and cin.getline (char* s, streamsize n, char delim ); 
// is almost the same thing. The first one doesn't discard delim from input stream however.

// The third cin.get(a,256) reads a whole line but leaves the end-of-line character in the stream, 
// so that repeating this will give no more input


//StringStream

// Using stringstream
// https://www.youtube.com/watch?v=Old5zufUh1Q
// A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream.



//Reading from stream using >>
//streamName>>whereToStore;(word by word)

//Create  stream string  using <<
//streamName<<val<<val2;

//streamName.str() //get entire stream string 
int main()
{
    stringstream ss("helloo my name is digvijay");

    while(!ss.eof())//rember !ss.endOfFile()
    {
        string iter;

        ss>>iter;

        cout<<iter;
    }

    
}


// Tokenizing a string using stringstream
#include <bits/stdc++.h>

using namespace std;

int main()
{

    string line = "GeeksForGeeks is a must try";

    // Vector of string to save tokens
    vector<string> tokens;

    // stringstream class check1
    stringstream check1(line);

    string intermediate;

    // Tokenizing w.r.t. space ' '
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    // Printing the token vector
    for (int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';
}

//Dellimitter

//stoi()-string to integer

int main()
{
}