

// Second loop mei galti ho jate hai kabhi kabhi
// j=0 se start kar deta hu agr duplicates nahi hai to i+1 se start hoga

// https://practice.geeksforgeeks.org/problems/addition-of-two-square-matrices4916/1
// Subtraction

// Multiply Two Matrix

// as we want sum of product of ith row and jth col  - n  elements for eij

// k->0 to n-1
// a[i][k] ->ith row
// a[k][j] ->jth col

//  for(int k=0;k<n;k++)
// product +=a[i][k]*a[k][j];

so int main()
{

        int n = 2, m = 2;
        int a[n][m] = {{2, 5}, {1, 7}};
        int b[n][m] = {{3, 7}, {2, 9}};

        int c[n][m];
        int i, j, k;
        for (i = 0; i < n; i++)
        {
                for (j = 0; j < n; j++)
                {
                        c[i][j] = 0;
                        for (k = 0; k < n; k++)
                                c[i][j] += a[i][k] * b[k][j];
                }
        }

        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                        cout << c[i][j] << " ";
                cout << endl;
        }
}

// Boolean Matrix

// Idea is to seperately solve for first row and first col  using  row1 and col1 two variables for first row and first col
// and store for the remaining matrix to corresponding 1st row and 1st col cells

// Function to modify the matrix such that if a matrix cell matrix[i][j]
// is 1 then all the cells in its ith row and jth column will become 1.
void booleanMatrix(int R, int C, int matrix[][C])
{
        int row1 = 0;
        int col1 = 0;

        // iterating through first row and marking in row1 variable
        for (int i = 0; i < C; i++)
        {
                if (matrix[0][i] == 1)
                        row1 = 1;
        }

        // iterating through first col and marking in col1 variable
        for (int i = 0; i < R; i++)
        {
                if (matrix[i][0] == 1)
                        col1 = 1;
        }

        // matrix cell matrix[i][j]
        // is 1 then marking in 1st row and 1st col that
        // all the cells in its ith row and jth column will become 1.
        for (int i = 1; i < R; i++)
        {
                for (int j = 1; j < C; j++)
                {
                        if (matrix[i][j])
                        {
                                matrix[i][0] = matrix[0][j] = 1;
                        }
                }
        }

        // itreate through first col if marked 1 then mark corresponding rows to 1
        for (int i = 1; i < R; i++)
        {
                if (matrix[i][0])
                {
                        for (int j = 1; j < C; j++)
                        {
                                matrix[i][j] = 1;
                        }
                }
        }

        // itreate through first row if marked 1 then mark corresponding cols to 1
        for (int j = 1; j < C; j++)
        {
                if (matrix[0][j])
                {
                        for (int i = 1; i < R; i++)
                        {
                                matrix[i][j] = 1;
                        }
                }
        }

        if (row1)
        {
                for (int j = 0; j < C; j++)
                {
                        matrix[0][j] = 1;
                }
        }
        if (col1)
        {
                for (int i = 0; i < R; i++)
                {
                        matrix[i][0] = 1;
                }
        }
}

// https://www.youtube.com/watch?v=JkWDKg_pNME&list=PLzffTJx5aHaRMfFodb4O5yyi6uSA4Q3E0&index=21
// Spiral matrix
//

row = matrix.size();
col = matrix[i].size();

(row, j)-- -- --->

        (i, col)

        ^
    |
    |
    |

    // indexing using minus one rule
    0 1 2
    //      j---->
    //      |
    // 0  i--[[0,1,2]
    // 1  |  ,[3,4,5]
    // 2  |  ,[6,7,8]]

    // How to find neighbours?
    // i-1,j ->up
    // i+1,j ->down
    // i,j+1 ->right
    // i,j-1)->left

    // boundary check->
    //

    // Row with Maximum 1's

    // Replace all row and col zero

    // Trapspose

    // Rotate 90 180 270

    // Diagonal Traversal

    // Spiral Traversal

    // Search in Matrix I

    // Search in Matrix II

    // https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
    class Solution
{
public:
        // Easy apporach using heap
        int kthSmallest(vector<vector<int>> &matrix, int k)
        {
                // as we need to find the kth smallest element
                // it also means it is larger other k-1 smallest elements

                // so we can maintain a maxheap of size k
                // and its largest element is going to give us the kth smallest element

                // Genenral Algo:
                // kth smallest->maxheap
                // kth largest->minheap

                // keep pushing
                // if size of heap is greater than k pop
                // at the end return top

                priority_queue<int> pq; // default is maxheap

                for (int i = 0; i < matrix.size(); i++)
                {
                        for (int j = 0; j < matrix[0].size(); j++)
                        {
                                pq.push(matrix[i][j]);
                                if (pq.size() > k)
                                {
                                        pq.pop();
                                }
                        }
                }

                return pq.top();
        }
};