#include <bits/stdc++.h>

using namespace std;
//Q.1Max or Min Element in Array
//ALGO:Maximize max-element variable
int maxElement(int arr[], int n) //we have to pass size with arr
								 // as they are passed as pointers
{
	int maxNum = arr[0];
	for (int i = 1; i < n; i++)
	{
		maxNum = max(maxNum, arr[i]); //maximizing maxNum

		//OR

		if (maxNum < arr[i])
		{
			maxNum = arr[i];
		}
	}

	return maxNum;
}

//Q. Find Second Largest Element
//ALGO:
// maintain two variables
//largest and second largest
//if current val is greater than currlargest then assingn it to largest and out largest become second largest
//if current val is less than currlargest then if it is greater than second largest assing it to second largest
int secondLargest(int arr[], int n)
{
	int largest = arr[0];
	int secondLargest = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > largest)
		{
			secondLargest = largest;//IMP : first this -> whenver u are putting one var value to another make sure it is not begin changed
			largest = arr[i];	
		}
		else if (arr[i] > secondLargest)
		{
			secondLargest = arr[i];
		}
	}
	return secondLargest;
}

int main()
{
}