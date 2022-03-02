
// Concept:How to traverse both diagonals?
// abs diffrence b/w sum of both the digagonals
int diagonalDifference(vector<vector<int>> arr)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < arr.size(); i++)
        sum1 += arr[i][i];
    int j = arr.size() - 1;
    for (int i = 0; i < arr.size(); i++)
        sum2 += arr[i][j], j--;
    return abs(sum1 - sum2);
}

// Concept:Sum of Array elements, Using long long int to avoid overflow

// The method can be used with unsigned integers too :

int a = <something>;
int x = <something>;
if ((x > 0) && (a > INT_MAX - x))
{
    /* `a + x` would overflow */
}
if ((x < 0) && (a < INT_MIN - x))
{
    /* `a + x` would underflow */
}

// For subtraction
int a = <something>;
int x = <something>;
if ((x < 0) && (a > INT_MAX + x))
{
    /* `a - x` would overflow */
}
if ((x > 0) && (a < INT_MIN + x))
{
    /* `a - x` would underflow */
}

// For multiplication
int a = <something>;
int x = <something>;
// There may be a need to check for -1 for two's complement machines.
// If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
if ((a == -1) && (x == INT_MIN))     /* `a * x` can overflow */
    if ((x == -1) && (a == INT_MIN)) /* `a * x` (or `a / x`) can overflow */
        // general case
        if (x != 0)
        {
            if (a > INT_MAX / x)
            {
                /* `a * x` would overflow */
            }
            if ((a < INT_MIN / x))
            {
                /* `a * x` would underflow */
            }
        }

// For division
(except for the INT_MIN and -1 special case), there isn t any possibility of going over INT_MIN or INT_MAX.


//Precision in floating point nos?
//int / int is integer 
//Ceil,Floor,round,fixed and setprecision
// https://www.geeksforgeeks.org/precision-of-floating-point-numbers-in-c-floor-ceil-trunc-round-and-setprecision/
//Nos can be classified as : zero or (non-zero-> +ve or -ve)
