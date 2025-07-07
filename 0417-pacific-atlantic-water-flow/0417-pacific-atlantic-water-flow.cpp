class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>> Atlantic(heights.size(),vector<int>(heights[0].size(),0));

        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                if(j == 0 || i == 0) pacific[i][j] = 1;
                if(j == heights[0].size()-1 || i == heights.size()-1) Atlantic[i][j] = 1;
            }
        }

        queue<pair<int,int>> q;

        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                if(pacific[i][j] == 1 || Atlantic[i][j] == 1) q.push({i,j});
            }
        }

        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};

        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && heights[nx][ny] >= heights[x][y]){
                    if(pacific[x][y] == 1 && !pacific[nx][ny]){
                        q.push({nx,ny});
                        pacific[nx][ny] = 1;
                    }

                    if(Atlantic[x][y] == 1 && !Atlantic[nx][ny]){
                        q.push({nx,ny});
                        Atlantic[nx][ny] = 1;
                    }
                }
            }

        }

        vector<vector<int>> ans;

            for(int i=0; i<heights.size(); i++){
                for(int j=0; j<heights[0].size(); j++){
                    if(pacific[i][j] == 1 && Atlantic[i][j] == 1) ans.push_back({i,j});
                }   
            }

            return ans;


    }
};