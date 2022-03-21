//Sorting
//Inc - Decreasing
//a[i]>a[j] -> LIS



// Bubble Sort

void bubble(vector<int>& nums)
{
    for(int i=0;i<n-1;i++)//if we have sorted n-1 elements then entire array is sorted
    {

    }
}
// Selection Sort
// Insertion Sort
// Quick Sort
// Merge Sort
// Heap Sort




//Q.Minimum inc/dec operations to make two arrays equal
// https://www.geeksforgeeks.org/making-elements-of-two-arrays-same-with-minimum-incrementdecrement/

// Algorithm : 
// 1. First sort both the arrays. 
// 2. After sorting we will run a loop in which we compare the first and second array elements and calculate the required operation needed to make first array equal to second.
// Below is the implementation of the above approach

int MinOperation(int a[], int b[], int n)
{
    // sorting both arrays in
    // ascending order
    sort(a, a + n);
    sort(b, b + n);
 
    // variable to store the
    // final result
    int result = 0;
 
    // After sorting both arrays
    // Now each array is in non-
    // decreasing order. Thus,
    // we will now compare each
    // element of the array and
    // do the increment or decrement
    // operation depending upon the
    // value of array b[].
    for (int i = 0; i < n; ++i) {
        result = result + abs(a[i] - b[i]);
    }
 
    return result;
}


//If we want one array close to another sort them

