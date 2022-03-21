//Q.Rotate array by 1
//Left and Right Rotation

// In the left rotation, each element of the array will be shifted to its left
// by one position and the first element of the array will be added to end of
// the list.



 //Q.Reversal Algo For left Rotating K times 

//reverse first k and k+1 to n
//and then reverse entire array 



//Eg  1 2 3 4 5 7

//rotate left by 3


// 3 2 1 7 5 4 -> reverse first 3 and 4 to 6

// 4 5 7 1 2 3 ->reverse entire to get rotate by 3


//Q.Similarly we can convert a rotated array to Sorted Array 
//

//Eg: 
// 4 5 7 1 2 3  convert a rotated array to Sorted Array 

//  Reverse entire
// 3 2 1 7 5 4
//  Revese first k
// 1 2 3 7 5 4
//Reverse last k+1 to n
//1 2 3 4 5 7 -> SOrted Array



//Check if an array is Sorted and Rotated
//Love Babbar video

//Using comparision adjacent count:)
// -> a[i-1]>a[i]

// 1 2 3 4 5 ->count 1 (cyclic one 5->1)
 
// 2 3 4 5 1 ->count 1 ( one at 5 1)

//1 1 1 -> count=0 

//1 3 4 2  ->count ==2 ( one 2 1 + one 4 2) ->invalid


