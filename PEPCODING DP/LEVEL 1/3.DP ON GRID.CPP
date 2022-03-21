
// 64. Minimum Path Sum: https://leetcode.com/problems/minimum-path-sum/
//  find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // Path problem

        // given
        //(i,j)->(i+1,j) down or (i,j+1) right
        // to calculate f(i,j) => grid[i][j]+ min(f(i+1,j),dp(i,j+1)) //recurrence

        // (i-1,j) ,(i,j-1)->(i,j) //reverse
        // Basically we can reach (i,j) from or (i,j-1) (i-1,j)

        // dp[i][j] gives minimum path sum to reach (i,j)

        // dp[i][j] = dp[i][j](current contribution)+min(dp[i][j-1],dp[i-1][j]); // top-down conversion

        //           (i-1,j)
        //             |
        // (i,j-1) --(i,j)
        // To calculate i,j we need to know the ans of (i-1,j) and (i,j-1) states
        // so traverse in row-major order

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 && j == 0)
                    grid[i][j] = grid[i][j];
                else if (i == 0)
                    grid[i][j] = grid[i][j] + grid[i][j - 1];
                else if (j == 0)
                    grid[i][j] = grid[i][j] + grid[i - 1][j];
                else
                    grid[i][j] = grid[i][j] + min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[rows - 1][cols - 1];
    }
};

// GoldMine:
//  https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
public:
    int rows, cols;
    int getVal(int i, int j, vector<vector<int>> &matrix)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols) // out of boundary
            return INT_MAX;
        return matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        // Recursive
        // at every cell we have three choices
        //(row, col) -> (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
        // contribution+ min or max {call(),,}->we have faith that calls will give correct ans
        // f(row,col)= matrix[i][j]+min({f(row + 1, col - 1), f(row + 1, col), f(row + 1, col + 1)})

        // DP:
        // contribution+ min or max {CaculatedSubProblems()}
        //(row-1,col+1) , (row-1,col) , (row-1,col-1) -> (row,col)  [REVERSE CONCEPT]

        // (row-1,col-1) (row-1,col) (row-1,col+1)  //SUBPROBLEMS NEED TO BE CALCULATED FIRST:so row major traversal
        //        \          |            /
        //                (row,col)                 //TO SOLVE BIGGER PROBLEM

        // matrix[i][j] itself can be used as dp
        // dp[i][j] represents minimum sum to reach

        rows = matrix.size();
        cols = matrix[0].size();
        for (int i = 1; i < rows; i++) // start from second row
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] += min({getVal(i - 1, j - 1, matrix), getVal(i - 1, j, matrix), getVal(i - 1, j + 1, matrix)});
            }
        }

        return *min_element(matrix[rows - 1].begin(), matrix[rows - 1].end());
    }
};
// Ideal Solution:
//  https://leetcode.com/problems/minimum-falling-path-sum/discuss/964191/Dynamic-Programming-Solution

// https://leetcode.com/problems/triangle/

class Solution
{
public:
    int rows;
    int getVal(int i, int j, vector<vector<int>> &triangle)
    {
        if (i < 0 || i >= rows || j < 0 || j >= triangle[i].size()) // out of boundary
            return INT_MAX;

        return triangle[i][j];
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {

        // given
        //(i,j) ->  ((i+1,j+1) (i+1,j))
        //(i-1,j-1) , (i-1,j)
        rows = triangle.size();
        for (int i = 1; i < rows; i++) // start from second row
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                triangle[i][j] += min({getVal(i - 1, j - 1, triangle), getVal(i - 1, j, triangle)});
            }
        }

        return *min_element(triangle[rows - 1].begin(), triangle[rows - 1].end());
    }
};




//https://leetcode.com/problems/unique-paths/submissions/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
            
        //(i,j) -> (i+1,j) ,(i,j+1)
            
        //(i-1,j) , (i,j-1) -> (i,j)
        
        
        //ways(i,j) ->ways to reach (i,j)
        //recurrece:
        //ways(i,j) = ways(i,j-1)+ways(i-1,j)
        
        //Base cases:
        //i==0 or j==0 
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};



// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
            
        //(i,j) -> (i+1,j) ,(i,j+1)
            
        //(i-1,j) , (i,j-1) -> (i,j)
        
        
        //ways(i,j) ->ways to reach (i,j)
        //recurrece:
        //ways(i,j) = ways(i,j-1)+ways(i-1,j)
        
        //Base cases:
        //(0,0) reach = 1
        //isObstacle ways to reach = 0
        //i==0 or j==0 ways -> prev element
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else if(i==0&&j==0){
                    dp[i][j]=1;
                }else if(i==0)
                    dp[i][j]=dp[i][j-1];
                else if(j==0)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};


//CHerry  Pick up

//CHerry  Pick up-II

//Dungeon Game




//Champane Tower
// https://www.youtube.com/watch?v=POuK_Ng5INo

