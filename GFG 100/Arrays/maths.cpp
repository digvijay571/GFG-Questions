// Integers-Zero and Non-Zero
// Non-Zero- Positive and Negative

// What is Prime Nos
// Prime no. are which have 1..and itself as it only two factors among 1...N
// 1 is not prime
// 1 is neither prime nor composite
// Questions:
// Sieve
// Segmented Sieve
// Prime Factorization

// Factorial: n! =  product of 1 to n
// n! = n*(n-1)!
// Ques: Trailing zeros in n!

// Permutation:Ways to Arrange a sequnce

// Combination:ways to choose n from r

// Maximum->gretest among all - greater than any
// Minimum->gretest among all - greater than any

// minimum......maximum
// sorted -> nums[i+1]>nums[i] -increasing

// Median->sort then middle

// AP-common  diffrence same- > a b c  = (a+c)/2 = b
// GP-ratio same -> b^2=ac

// Roman to Interger
// Integer to Roman

// Find Odd nos beteween high and low
// the count of odd numbers between 1 and low - 1 is low / 2
// the count of odd numbers between 1 and high is (high + 1 ) / 2
int countOdds(int low, int high)
{
        return (high + 1) / 2 - low / 2;
}

// How to spit nos
// We generally use base 10 Nos
//  let a no. be abc
//  c can be obtained by abc%10 .. i.e if we take modulo with 10^n we can get last n digits
// ab can be obtained by abc/=10;  i.e if we take modulo with 10^n we can get totaldigits-n from start digits

// to get ab0 we can do abc-=abc%10;

// a%b = say a mod b = remainer when a is divided by b
//  (a + b) % m = ((a % m) + (b % m)) % m
//  a>=b then (a - b) % m = ((a % m) - (b % m)) % m
//  (a x b) % m = ((a % m) x (b % m)) % m

// Binary exponentiation:https://leetcode.com/problems/powx-n/

double pow2(double a, int b) // a^b
{
        if (b == 0)
                return 1;

        double p = pow2(a, b / 2);

        if (b % 2 == 0)
                return p * p;

        if (b > 0)
                return a * p * p;
        else
                return 1 / a * p * p;
}

double myPow(double x, int n)
{
        return pow2(x, n);
}

long long int mod = 1e9 + 7; // 10^9+7

// How to make Nos Using digits?

// For eg:
// 1,2,3
// there are two ways:
// 1.TO get the same order we can maitain 10 powers
int n = 0;
int pow10 = 1;
for (auto digit : digits)
{
        n = n + pow10 * digit;
        pow10 *= 10;
}
int n = 0;
for (auto digit : digits)
{
        n = n * 10 + digits;
}
// 1.TO get the reverse order we can extract the last digit
// mul the nos by 10 which is alredy formed and add last digit to it

int n = 0;
for (auto lastdigit : digits)
{
        n = n * 10 + lastdigits;
}

// How to reverse in Binary:Application of shifting insted of mul by 10
uint32_t reverseBits(uint32_t n)
{
        int reverseNum = 0;
        for (int i = 0; i < 32; i++)
        {
                reverseNum <<= 1;      // left shift reverse num by 1
                reverseNum |= (n & 1); // get the last bit and mark it in reverse NUm
                n >>= 1;               // revemove last bit
        }
        return reverseNum;
}

// Q.How to convert One base into another

// A base B means
// A is a no. in base B
// restrinction of a base B nos. are
// digits in A are < B
// The weight of  digit are  B^0 B^1 B^2 ....

// Let we want to convert Base B to C
// To Convert to Any base first we need to convert B to base 10 then 10 to C
// Conversion of 10 is easy we just need to muliply the digits by weight (B) and add them up
//  Step 1 − Convert to Decimal
//  Step	Octal Number	Decimal Number
//  Step 1	258	((2 × 8^1) + (5 × 8^0))
//  Step 2	258	(16 + 5 )10
//  Step 3	258	2110

// For conversion of Base 10 to C
// we divide by C (i.e.Base to be converted) to get quotient unit it is zero -> get the remainder and for a no. by mul 10 each time

// Convert Decimal to Binary
// Step	       Operation	Result	Remainder
// Step 1	21 / 2	        10	    1
// Step 2	10 / 2	        5	    0
// Step 3	5 / 2	        2	    1
// Step 4	2 / 2	        1	    0
// Step 5	1 / 2	        0	    1
// Binary No.(10101)base2

// How to add Two nos?
// Sum=A+B+Carry
//    if(Sum>=Base)
//     {
//          Sum = Sum-Base;
//          Carry=1;
//     }
//     else
//     {
//          Carry=0;
//     }

// How to Multiply Nos?
//

// Xor
//  x^x==0 and x^0 ==x
//  odd num of times one val will be left from it, all letters appear even no. of times time so their xor is going to be zero
// val^0 = val
class Solution
{
public:
        char findTheDifference(string s, string t)
        {

                char diff = 0;
                for (auto &c : s)
                        diff ^= c;
                for (auto &c : t)
                        diff ^= c;
                return diff;
        }
};

// Gray Code:https://www.google.com/imgres?imgurl=https%3A%2F%2Fstatic.javatpoint.com%2Ftutorial%2Fdigital-electronics%2Fimages%2Fgray-code.png&imgrefurl=https%3A%2F%2Fwww.javatpoint.com%2Fgray-code-in-digital-electronics&tbnid=5yHXjsLtV3akNM&vet=12ahUKEwiQ1oSNp4r2AhWRAjQIHbuqAXYQMygHegUIARDjAQ..i&docid=1GtkOZ1sf_ZTyM&w=402&h=283&q=gray%20code&ved=2ahUKEwiQ1oSNp4r2AhWRAjQIHbuqAXYQMygHegUIARDjAQ
//   An n-bit gray code sequence is a sequence of 2^n integers where:
//  Every integer is in the inclusive range [0, 2n - 1],
//  The first integer is 0,
//  An integer appears no more than once in the sequence,
//  The binary representation of every pair of adjacent integers differs by exactly one bit, and
//  The binary representation of the first and last integers differs by exactly one bit.
vector<int> grayCode(int n)
{
        vector<int> gc;
        for (int i = 0; i < pow(2, n); i++)
        {
                gc.push_back(i ^ (i / 2));
        }
        return gc;
}

// SOME COMMONLY USED OBSERVATIONS
//  Odd+Odd=even
//  odd^odd=even //as last bit is going to be unset  as 1^1 = 0 (trick (1+1)%2 = 0)

// even+odd = odd
// even^odd = odd

// Odd+even = odd
// odd^even= odd

// even+even=even
// even^even=even
// if with same no. we add even and odd or xor any where with several nos the final output wil either be even or odd but diffrent for both of them
// Basically Observe the parity of last bit

//