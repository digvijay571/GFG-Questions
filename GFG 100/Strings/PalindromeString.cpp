//Palindrome is a string in which
//same reads from forward and backwark
//s=rev(s)

//if we take mirror of a string it becomes palindrome

//Check recusively

bool isPalindrome(int i,int j,string & s)
{
    if(i>=j) return 1;

    if(s[i] != s[j]) return 0;

    return isPalindrome(i+1,j-1,s);
}


//Given Two String we can apply two operations:
//can we convert one into another.

//We can swap charaters

//IDea is if frequecy is same then we can swap and make same string:Permuation

//we can change one charater of a string  to another charater of another string at all places 

//Idea is we can make one string to another string if sorted of frequencies is same for both the strings




//Can i rearrange   a string into  k palindromic partions ?
//There can be two types of Palindrome:
//Odd Palindrome:Freqency of one element is odd and other are even  
//aca

//Even Palindrome:Freqency of all elements if even
//abba



