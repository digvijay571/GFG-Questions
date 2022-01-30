//Q. find no. of substrings that contain first vowels and last consonants
//idea is to maintain sum to count all substring
//maintain vowels and consonants count before a character 

//if a character is vowel then add consonats number to sum and vowel++

//if a character is consonant then add vowel number to sum and cons++

//to get the required substrings



//Q. find no. substrings which have same first and last character

//this can  be done in linear time by calculating frequency of each character
//then iterating through frequency map and keep on adding while
// applying formula fmp[i]*(fmp[i]+1)/2

// For example in string abcab, frequency of ‘a’ is 2, 
// and substrings contributing to answering are a, abca and a respectively, 
// a total of 3, which is calculated by (frequency of ‘a’+1)C2. 


//Q. Count Total Vowels in a all substring
//to find all 
void CountVowels(string &s)
{
    int count = 0;
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (isVowel(s[i]))
        {
            count += n - i; //these are substring starting with this vowel

            //abcdefghi
            //012345678
            //n=9
            //i=4
            //e,ef,efg,efgh,efghi - 5
            //n-i=5

            //now attach 0 to 3 =4=i  charaters to above n-i substring to get remaining substrings
            //i.e (n-i)*i;

            count += 1LL * (n - i) * i; //i are the number of charaters which are before current charater
                                        //and n-i are the substring which can be made containing current vowel
                                        //1LL is to avoid overflow of n-i*i 
        }
    }
}




//Q. find substring with all vowels

       
// For every character,
//  If current character is vowel then insert into hash. 
//  Else set flag Start to next substring start from i+1th index. 
//  If all vowels are included, we print the current substring. 



 
// Returns true if x is vowel.
bool isVowel(char x)
{
    // Function to check whether a character is
    // vowel or not
    return (x == 'a' || x == 'e' || x == 'i' ||
                        x == 'o' || x == 'u');
}
 
// Function to FindSubstrings of string
void FindSubstring(string str)
{
    set<char> hash;  // To store vowels
 
    int start = 0;
    for (int i=0; i<str.length(); i++)
    {
        // If current character is vowel then
        // insert into hash ,
        if (isVowel(str[i]) == true)
        {
            hash.insert(str[i]);
 
            // If all vowels are present in current
            // substring
            if (hash.size()==5)
                cout << str.substr(start, i-start+1)
                     << " ";
        }
        else
        {
            start = i+1;
            hash.clear();
        }
    }
}



//Great Questions to get idea of integer valid

// Is 1u ( which may be a representation for unsigned integers valid?

// For this problem, no.

// Is 0.1e10 valid?

// Yes

// -01.1e-10?

// Yes

// Hexadecimal numbers like 0xFF?

// Not for the purpose of this problem

// 3. (. not followed by a digit)?

// No

// Can exponent have decimal numbers? 3e0.1?

// Not for this problem.

// Is 1f ( floating point number with f as prefix ) valid?

// Not for this problem.

// How about 1000LL or 1000L ( C++ representation for long and long long numbers )?

// Not for this problem.

// How about integers preceded by 00 or 0? like 008?

// Yes for this problem


// Questions:

// Q1. Does string contain whitespace characters before the number?

// A. Yes

// Q2. Can the string have garbage characters after the number?

// A. Yes. Ignore it.

// Q3. If no numeric character is found before encountering garbage characters, what should I do?

// A. Return 0.

// Q4. What if the integer overflows?

// A. Return INT_MAX if the number is positive, INT_MIN otherwise.