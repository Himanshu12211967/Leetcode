class Solution {
public:

    void dfs(vector<vector<char>>& grid,int x,int y){

        grid[x][y] = '0';
        int dx[] = {0,0,1,-1,};
        int dy[] = {1,-1,0,0};

        for(int i=0; i<4; i++){

            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == '1'){
                dfs(grid,nx,ny);
            }

        }


    }

    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }

        return count;

    }
};