class Solution {
public:

    bool solve(vector<vector<int>> &grid, int x, int y, int n,int k){

        if(k == n*n) return true;
        if(grid[x][y] != k) return false;

        int dx[] = {2,2,1,-1,-2,-2,-1,1};
        int dy[] = {1,-1,-2,-2,-1,1,2,2};

        for(int i=0; i<8; i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                if(solve(grid,nx,ny,n,k+1)) return true;
            }

        }

        return false;

    }

    bool checkValidGrid(vector<vector<int>>& grid) {

        int n = grid.size();

        bool ans = solve(grid,0,0,n,0);

for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                cout<<grid[i][j]<<" ";
            }cout<<endl;
        }

        return ans;

    }
};