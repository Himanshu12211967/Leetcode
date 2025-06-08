class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1) continue;
                int right = (j+1 < n) ? grid[i][j+1] : INT_MAX;
                int down = (i+1 < m) ? grid[i+1][j] : INT_MAX;
                grid[i][j] += min(down,right);
            }
        }

        return grid[0][0];

    }
};