class Solution {
public:

    bool solve(vector<vector<char>>& board, string &word,int index,int i,int j){

        if(index == word.length()) return true;

        char ori = board[i][j];
        board[i][j] = '*';
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int k=0; k<4; k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == word[index]){
                if(solve(board,word,index+1,nx,ny)) return true;
            }

        }


        board[i][j] = ori;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(word[0] == board[i][j]){
                    if(solve(board,word,1,i,j)) return true;
                }
            }
        }

        return false;

    }
};