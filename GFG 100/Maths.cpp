#include<bits/stdc++.h>

using namespace std;

//Q1 GRAY CODE
//  An n-bit gray code sequence is a sequence of 2^n integers where:
// Every integer is in the inclusive range [0, 2n - 1],
// The first integer is 0,
// An integer appears no more than once in the sequence,
// The binary representation of every pair of adjacent integers differs by exactly one bit, and
// The binary representation of the first and last integers differs by exactly one bit.
//CONCEPT:i->0..pow(2,n)-1 , ith gray code = i xor (i/2);
// https://assets.leetcode.com/users/images/2f2a55fd-e72e-4b8b-98ca-f6c43cf8c46e_1642947834.2559333.png
vector<int> grayCode(int n) {
	vector<int> gc;
    for(int i=0;i<pow(2,n); i++)
    {
        gc.push_back(i^(i/2));
    }
    return gc;]]]
 }

int main()
{

}