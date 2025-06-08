class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i=0; i<matrix.size(); i++){

            int left = 0,right = matrix[0].size()-1;

            while(left <= right){
                if(matrix[i][left] == target || matrix[i][right] == target) return true;
                left++;
                right--;
            }

        }

        return false;
        
    }
};