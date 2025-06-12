class Solution {
public:

    int solve(vector<vector<int>> board,int x,int y){

        int dx[] = {0,0,1,-1,-1,-1,1,1};
        int dy[] = {1,-1,0,0,-1,1,-1,1};

        int live = 0;

        for(int i=0; i<8; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx >= 0 &&  ny >= 0 && nx < board.size() && ny < board[0].size() && (board[nx][ny] == -1 || board[nx][ny] == 1)) live++;
            
        }

        if(board[x][y] == 0 && live == 3) return 2;
        if(board[x][y] == 1 && (live < 2 || live > 3)) return -1;
        return board[x][y];
    }

    
    void gameOfLife(vector<vector<int>>& board) {

        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> matrix(row,vector<int>(col,0));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int val = solve(board,i,j);
                board[i][j] = val;
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                board[i][j] = (board[i][j] <= 0) ? 0 : 1;
            }
        }
    }
};