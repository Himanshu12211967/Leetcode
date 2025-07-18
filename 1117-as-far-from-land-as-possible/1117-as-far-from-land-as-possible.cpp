class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int max_dist = -1;
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        if(q.size() == n*n) return -1;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0; i<4; ++i){

                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != 1){
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                    }

                }
            }

            ++max_dist;
        }

        return max_dist;

    }
};