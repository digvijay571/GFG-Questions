// type a;
// variable are nick names,
// check once the type before using the var
// DECLATATION AND SCOPE
// int a; say interger a

// func is code nick name

// whenver u change a variable name in declaration make sure to change whereever u used it

// what we have to use we pass:) in function
//  same for funtion parameter-if a function parameter is added then -refereces , must be passed in all function call

// what we have to calculate ->decides return type of funtion

// int a[n];//garbage val initialized
// access = a[idx] ->using a[indexing]
// a n size array has valid indexes from 0 to n-1
// int a[0]=1;//idx=n-1

// what are elements between two indexes i,j j>i
// j-i ->gives me the len including either of them
// j-i+1 //gives me the len including both of them
// j-i-1 //gives me the len including neither of them ->elements between i and j index

// sort(a.begin(),a.end(),comp);
// comp(type i1,type i2)
//  {
// condition which need to be satified so that i1,i2 order is maintained
// }

// Brakets can be used to avoid precedence and associavity rules

// type knowlege:
// type casting : int/int = int to get floating we do (int*1.0)/int
// overflow (int*int)=int  (int*int*1LL)=>long multiplication
//'a'+1 ->'b'ASCII VALUE : a converted to Assci val and added to one
// c-'a' to get corresponding idx in frequency map

//#define ll long long ->for bigger interger As we cannot store 10^10 val in integer(10^5 > nums when to use long long?)
// always use ll at all places
// see if product can go beyond int then also use *1LL

// int,bool-true or false,char-'single char',string-"double qouted"-array of char,vector<int> ,vector<string>  or 2D array of char

// whever array commes cal its size n=arr.size()
//  vector<int> nums(n,0); nums[i] -> num

// val  A[1,3,2,5]
//        | | | |
// idx    0 1 2 3

//  idx=n-1
// 0<=idx<n

// ptr -> points to type
// variable ya obeject ka address store karata hai
//* derefrece (commonly used for simple var) or -> (for objects)

// Object -> variable of class
// class is a user defined data-type
// class name{
//  public:
//  name()
//  {

//  }
// };

// we can cherry pick members and meberfunction through object . or object-> pointer

// meaning ful Nick names are of variables and functions

// output=fuc(input)
//  returntype name(type parameters)//type and reference
//   {
//  body
//   return returntype;
//  }
// name(validparameters);//CALL OR USE//order and type and reference

// for loop generally of two  types ->for accessing elements
// idx based  for(int i=0;i<n;i++){}
// element by element-> for(auto e:nums)

// PRIORITY QUEUE->EVERY TIME MIN-MAX
// STACK-LIFO-REVERSE
// QUEUE-FIFO-ORDER IS PRESERVERED OR JiS ORDER MEI INSERT KAREGE ... USEEE ORDER MEI RETRIVAL
// MAP-<KEY,VAL>
// SET-CHECKING PRESENCE

// RECURSION->1.BASE CASE 2.RECURSIVE CASE
// RECURSION IS LEAP OF FAITH

// BackTracking:
// backtrack when ?
// We undo while backTracking

// FOR - CONTROL STAMENTS CHECK PYTHON NOTES

//[0,1,2]
// |
// i--->

//      j---->
//      |
// i--[[0,1,2]
// |  ,[3,4,5]
//   ,[6,7,8]]

// rows = matrix.size()
// cols = matrix[0].size()
// boundary-> (i>=0&&j>=0&& i<=rows&&j<=cols)

// FOr each of element -> for(auto e:c) //element by element
// for(int i=0;i<n;i++) -> for(each i:[0 to n-1])

//(i,j)-
// for each i: [i to n-1]
// for(for each i all j:[0 to n-1])

// Eg:
// for each row
// for entire cols
// for(int i=0;i<n;i++)(
//      for(int j=0;j<n;j++)
//      {

//     }
// )

// Idendity Element:
// 0 - is for sum
// 1- is for multiplication
// INT_MAX->minimization
// INT_MIN->maximize

// Stack-> piche wale elements ka use baad mei karna ho to stack use karo Or Monotonic stack
//       ->aage walo ka ans phele calculate hoga phir phechec walo ka
// Queue-> jis order mei elements insert karte hai usee order mei use

// DP:max/min/count etc
// Decisions+Choices
// DP is optimizing recurrence
// Recurrence relation is Formed by making Decision+Choices block ( 1.starte variables, 2. state Transision (using Decisions+Choices), Base case  )
// After wrinting recurrece we can make recusion Tree to see the overlaping subproblems

// We make a dp table-> array if variables are positive intergers OR hashmap;
// Initialize it with -1 indicating problem is not calculated
// whenver solve a subproblem -> return statement , store it in DP Table

// Substring-contiguous
// Subsequence->

// STL-

// Common Funtions are:

// iterators are special pointers-which can also be dereference to get the content to which they are pointing and pointer arthmetic can also be applied (constarints)
// begin()-starting iterator
// end()-ending iterator - genearally used in find also ,,,if not find then it reaches end:)

// binary_search(begin,end,val) ->true and false in a soreted array if an element is present

// lower_bound(begin,end,val) ->iterator to first occurence of element if present or the next higher val

// lower_bound(begin,end,val) ->iterator to first occurence of  next higher val

// random-> i+a , i-a valid (same as pointers)
// bidirectional->i++,i-- valid

// max_element()->iterator to max
// min_element()->iterator to min

//### end_iterator is not included in range i.e [start_iterator,end_iterator) ####

// find(start_iterator,end_iterator,val)-gives iterator to first val
// How to get index in case of vector?
// int idx=find()-(v.begin())

// reverse(start_iterator,end_iterator)

// sort(start_iterator,end_iterator)
// asc-default sorting based on values
//,dec-pass greater<int>() as last parameter-from C++14, you can even skip the template arguments, i.e., std::greater<int>() becomes std::greater<>().
// comparator funtion

// next_permutation()-makes next lexicographically greater permutation
//  https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/

Containers =

Containers can be described as the object that hold the data of the same type. Containers are used
to implement different data structures for example arrays, list, trees, etc.


=============================================================================
Pair
Pair of types
=============================================================================
Vector =

vector is a class that creates a dynamic array allowing insertions and deletions at the back.
Header file = <vector>
iterator = Random access
=============================================================================
List =

list is the sequence containers that allow the insertions and deletions from anywhere.
Header file = <list>
iterator = Bidirectional
=============================================================================
deque=

deque is the double ended queue that allows the insertion and deletion from both the ends.
Header file = <deque>
iterator = Random access
=============================================================================
set =

set is an associate container for storing unique sets.
Header file = <set>
iterator = Bidirectional
=============================================================================
multiset =

Multiset is an associate container for storing non- unique sets.
Header file = <set>
iterator = Bidirectional
=============================================================================
map =

Map is an associate container for storing unique key-value pairs, i.e. each key is associated with only
one value(one to one mapping).
Header file = <map>
iterator = Bidirectional
========================================================================
multimap =

multimap is an associate container for storing key- value pair, and each key can be associated with
more than one value.
Header file = <map>
iterator = Bidirectional
=============================================================================
stack =

It follows last in first out(LIFO).
Header file = <stack>
iterator = No iterator
=============================================================================
queue =

It follows first in first out(FIFO).
Header file = <queue>
iterator = No iterator



IMP Topics:Recursion ,DP, Graphs, Backtracking, Divide and Conquer, Sliding Window Binary search and Two pointers