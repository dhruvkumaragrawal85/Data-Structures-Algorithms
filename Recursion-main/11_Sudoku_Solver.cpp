//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    
        
    bool isvalid(int grid[N][N], int k, int i, int j)
    {
        for(int e=0; e<9; e++)
        {
            if(grid[e][j]==k)return false;
            if(grid[i][e]==k)return false;
            if(grid[3*(i/3)+e/3][3*(j/3)+e%3]==k)return false;
        }
        return true;
    }
    
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(grid[i][j]==0)
                {
                    for(int k=1; k<10; k++)
                    {
                        if(isvalid(grid, k, i, j))
                        {
                            grid[i][j]=k;
                            if(SolveSudoku(grid))
                            return true;
                            grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends