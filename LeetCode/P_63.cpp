/*
LeetCode problem : 63
Follow up for "Unique Paths" p_62:
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
*/

// Dynamic programming problem.

class Solution {
public:
    int uniquePaths(int m, int n) {
		// Allowed movements to only down and right. so i+1,j and i,j+1
    	int path_array[m][n];
		for (int i = 0; i < m ; i++) {
			// Intialize the rows. All will be 1 as the [rows][0] can be only reached by going
			// down.
			path_array[i][0] = 1;
		}   
		for (int j = 0; j < n; j++) {
			// Intialize the columns. All will be 1 as the [0][column] can be reached by going
			// right.
			path_array[0][j] = 1; 
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				path_array[i][j] = path_array[i-1][j] + path_array[i][j-1];
			}
		}
		return path_array[m-1][n-1];
    }
};