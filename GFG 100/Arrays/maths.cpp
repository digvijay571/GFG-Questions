
// Find Odd nos beteween high and low
// the count of odd numbers between 1 and low - 1 is low / 2
// the count of odd numbers between 1 and high is (high + 1 ) / 2
int countOdds(int low, int high)
{
        return (high + 1) / 2 - low / 2;
}

//How to spit nos
//We generally use base 10 Nos
// let a no. be abc
// c can be obtained by abc%10 .. i.e if we take modulo with 10^n we can get last n digits
//ab can be obtained by abc/=10;  i.e if we take modulo with 10^n we can get totaldigits-n from start digits

//to get ab0 we can do abc-=abc%10;

//How to make Nos Using digits?

//For eg:
//1,2,3
//there are two ways:
//1.TO get the same order we can maitain 10 powers
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
//1.TO get the reverse order we can extract the last digit
//mul the nos by 10 which is alredy formed and add last digit to it

int n = 0;
for (auto lastdigit : digits)
{
        n = n * 10 + lastdigits;
}

//How to reverse in Binary
uint32_t reverseBits(uint32_t n)
{
        int reverseNum = 0;
        for (int i = 0; i < 32; i++)
        {
                reverseNum <<= 1;      //left shift reverse num by 1
                reverseNum |= (n & 1); //get the last bit and mark it in reverse NUm
                n >>= 1;               //revemove last bit
        }
        return reverseNum;
}

//Q.How to convert One base into another

// A base B means
// A is a no. in base B
// restrinction of a base B nos. are
// digits in A are < B
// The weight of  digit are  B^0 B^1 B^2 ....

//Let we want to convert Base B to C
//To Convert to Any base first we need to convert B to base 10 then 10 to C
//Conversion of 10 is easy we just need to muliply the digits by weight (B) and add them up
// Step 1 − Convert to Decimal
// Step	Octal Number	Decimal Number
// Step 1	258	((2 × 8^1) + (5 × 8^0))
// Step 2	258	(16 + 5 )10
// Step 3	258	2110

//For conversion of Base 10 to C
//we divide by C (i.e.Base to be converted) to get quotient unit it is zero -> get the remainder and for a no. by mul 10 each time

// Convert Decimal to Binary
// Step	       Operation	Result	Remainder
// Step 1	21 / 2	        10	    1
// Step 2	10 / 2	        5	    0
// Step 3	5 / 2	        2	    1
// Step 4	2 / 2	        1	    0
// Step 5	1 / 2	        0	    1
// Binary No.(10101)base2

//How to add Two nos?
//Sum=A+B+Carry
//   if(Sum>=Base)
//    {
//         Sum = Sum-Base;
//         Carry=1;
//    }
//    else
//    {
//         Carry=0;
//    }

//How to Multiply Nos?
//
