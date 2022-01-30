#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dir;//direction vector
int rows,cols;


//is safe funtion to define boundary of the board(matrix)
bool isSafe(int i,int j,vector<vector<int>>& chess)
{
	if(i<0 || i>=rows || j<0 || j>=cols || chess[i][j]>0)
		return 0;
	return 1;
}


void knightTour(int i,int j,int totalmoves,int move,vector<vector<int>>&chess)
{
	//This is wrong as move is never going to be greater than totalmoves
	//so if we are always going to valid state then our base condition
	//is going to be last valid state

	// if(move>totalmoves){
	// 	return;
	// }


	if(move==totalmoves)
	{
		//display path
		return;
	}
    //Try all next moves from
    //the current coordinate i, j 
	for(int k=0;i<dir.size();k++)
	{
		int di = dir[k][0];
		int dj = dir[k][1];

		if(isSafe(i+di,j+dj,chess))
		{
			chess[i+di,j+dj]=move+1;//marking 
			knightTour(i+di,j+dj,totalmoves,move+1,chess);
			chess[i+di,j+dj]=0;//unmarking no need of visited array
		}
	}
}


//we can write same code in dfs fashion 
//base case is going to be move > totalMoves
//because when i am coming to a cell and if move is greater than totalMoves it means
//i have visited all cells as first i am going to that cell then marking it visited then moving forward
//unlike above apporach
//in which we are checking valid state first marking it then going to it so in that case
//when move is equal to total moves that means i have visited all cells 
//so it will be the base case
//2.and checking at starting for valid state and if valid marking it visited
//3.then exploring
//4.then unmarking 



int main()
{
	rows=chess.size();
	cols=chess[0].size();

	//make directions {i,j} in direction vector

	for(int i=-2;i<=2;i++)//range of i{-2...2}
	{
		for(int j=-2;j<=2;j++)//range of j{-2...2}
		{
			if(abs(i)+abs(j)==3) //condition for each knight move if center if(0,0)
				dir.push_back({i,j});
		}
	}

	knightTour(i,j,n*n,1,chess);
}