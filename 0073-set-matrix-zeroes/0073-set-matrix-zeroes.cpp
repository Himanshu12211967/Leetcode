class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstrow = false,firstcol = false;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 && matrix[i][j] == 0){
                    firstrow = true;
                }
                if(j == 0 && matrix[i][j] == 0){
                    firstcol = true;
                }

                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
    
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstrow){
            for(int i=0; i<m; i++){
                matrix[0][i] = 0;
            }
        }

        if(firstcol){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }

    }
};