class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int row = board.size();
        int col = board[0].size();

        int currpos = 1;
        int lastpos = row*col;

        queue<pair<int,int>> q;
        q.push({currpos,0});
        vector<int> visited(lastpos+1,0);
        visited[1] = 1;

        while(!q.empty()){

            currpos = q.front().first;
            int step = q.front().second;
            q.pop();

            if(currpos == lastpos){
                return step;
            }

            for(int i=1; i<=6; i++){
                int nextpos = currpos + i;
                if(nextpos > lastpos) break;
                int r = (row-1)-(nextpos-1)/col; // 6-0=4
                int c = (nextpos-1)%col;
                if ((row - 1 - r) % 2 == 1) {
                    c = col - 1 - c;
                }
                if(board[r][c] != -1) nextpos = board[r][c];
                if(!visited[nextpos]){
                    q.push({nextpos,step+1});
                    visited[nextpos] = 1;
                }
            }

        }

        return -1;
    }
};