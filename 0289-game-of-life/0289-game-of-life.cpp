class Solution {
public:

    int solve(vector<vector<int>>& board,int x,int y){

        int dx[] = {0,0,1,-1,-1,-1,1,1};
        int dy[] = {1,-1,0,0,-1,1,-1,1};

        int zero = 0;
        int one = 0;

        for(int i=0; i<8; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx >= 0 &&  ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 1) one++;
            if(nx >= 0 &&  ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 0) zero++;
        }

        if(board[x][y] == 0 && one == 3) return 1;
        if(board[x][y] == 1 && one < 2) return 0;
        if(board[x][y] == 1 && (one == 2 || one == 3)) return 1;
        if(board[x][y] == 1 && one > 3) return 0;
        return 0;
    }

    
    void gameOfLife(vector<vector<int>>& board) {

        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> matrix(row,vector<int>(col,0));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int val = solve(board,i,j);
                matrix[i][j] = val;
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                board[i][j] = matrix[i][j];
            }
        }
    }
};