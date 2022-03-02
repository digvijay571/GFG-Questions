#include<bits/stdc++.h>

using namespace std;


int main()
{	
	//Arrays-Arrays are Homogenous contiguous collection of data,data can be accessed using index(for a n size array index is from 0 to n-1 (positive))
	//Picture-> [1,8,3,6]
	            |  | |  |
		        0  1 2  3

	//An array data structure is used to store muliple items at one place with one name

	//For eg for facebook friend we can have 100 before then 500 after .. so we need a data structure which can store multiple items
	//i.e. array of friends


	//One important thing which makes it diffrent from other data stucture

	//Elements are stored at contiguous memory locations

	//Array elements are accessed using indexes (indexing in an array)


	//Advantages of Array:
	//Random access (find the ith element in constant time) 
	//and Cahe friendlyness

	//Cache is closest memory to CPU ...it is fastest than Ram and Hard dist ...
	//Ideally u want every item which program is accessing in cache

	//prefetching of nearby  array elements when we access an element



	//Based on Size we have 2 types of Arrays 
	//1.Fixed Size arrays
	//2.Dynamic Size arrays

	//Fixed size arrays can be allocated in stack memory or in heap memory(dynamic allocation)

	//Stack Allocated 

	//int arr[100];

	//int arr[n];

	//int arr[] ={1,2,3};//declares fixed size array of size 3

	//Heap Allocated

	// int* ptr = new arr[n];

	//Deallocate - delete [] ptr;



	//Dynamic size arrays in C++ - Vector

	//when dynamic array is full and we insert an element it doubles its size 
	//copy previous element and insert new element
	//we do not care about the capacity 


	//Insertion process at the endc in O(1) on an average


	//Dynamic size arrays are preffered over fixed size arrays
}