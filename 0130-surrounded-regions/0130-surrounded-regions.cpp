class Solution {
public:

    void dfs(vector<vector<char>>& board,int x,int y){

        board[x][y] = '#';
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int i=0; i<4; i++){

            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 'O'){
                dfs(board,nx,ny);
            }

        }


    }

    void solve(vector<vector<char>>& board) {
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1){
                    if(board[i][j] == 'O')
                    dfs(board,i,j);
                }
            }
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }

    }
};