class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> path(m,vector<int>(n,0));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1){
                    path[i][j] = 1;
                    continue;
                }

                int right = (j+1 < n) ? path[i][j+1] : 0;
                int bottom = (i+1 < m) ? path[i+1][j] : 0;
                path[i][j] = right + bottom;
            }
        }

        return path[0][0];

    }
};