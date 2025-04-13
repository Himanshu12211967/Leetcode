class Solution {
public:

    int solve(int row,int col,int n,int m,vector<vector<int>>& obstacleGrid){

        if(row >= 0 && col >= 0 && row < n && col < m && obstacleGrid[row][col] != -1) return obstacleGrid[row][col];
        return 0;
 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        //return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0]) return 0;

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 && j == m-1){
                    obstacleGrid[i][j] = 1;
                    continue;
                }

                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j]=-1;
                    continue;
                }

                long long right = solve(i,j+1,n,m,obstacleGrid);
                long long bottom = solve(i+1,j,n,m,obstacleGrid);
                obstacleGrid[i][j] = (right + bottom)%2000000000;

            }
        }

        return obstacleGrid[0][0];

    }
};