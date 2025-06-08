class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){

                if(i == m-1 && j == n-1){
                    obstacleGrid[i][j] = 1;
                    continue;
                }

                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = INT_MIN;
                    continue;
                }

                long long int right = 0,down = 0;

                if(j+1 < n && obstacleGrid[i][j+1] != INT_MIN) right = obstacleGrid[i][j+1];
                if(i+1 < m && obstacleGrid[i+1][j] != INT_MIN) down = obstacleGrid[i+1][j];

                obstacleGrid[i][j] = (down + right)%2000000000;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<obstacleGrid[i][j]<<" ";
            }
            cout<<endl;
        }

        return obstacleGrid[0][0];

    }
};