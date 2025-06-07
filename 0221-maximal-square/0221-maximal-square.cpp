class Solution {
public:

    void left(vector<int> &v,vector<int> &leftshift){

        stack<int> st;
    
        for(int i=0; i<v.size(); i++){

            while(!st.empty() && v[st.top()] >= v[i]) st.pop();

            if(st.empty()) leftshift[i] = 0;
            else leftshift[i] = st.top()+1;
            st.push(i);

        }


    }

    void right(vector<int> &v,vector<int> &rightshift){

        stack<int> st;
        int end_idx = v.size()-1;
        
        for(int i=end_idx; i>=0; i--){

            while(!st.empty() && v[st.top()] >= v[i]) st.pop();

            if(st.empty()) rightshift[i] = end_idx;
            else rightshift[i] = st.top()-1;
            st.push(i);

        }

    }

    int solve(vector<int> &v){

        vector<int> leftshift(v.size());
        vector<int> rightshift(v.size());

        left(v,leftshift);
        right(v,rightshift);

        int max_area = 0;
        
        for(int i=0; i<v.size(); i++){
            int height = v[i];
            int width = abs(leftshift[i]-rightshift[i])+1;
            int area = pow(min(height,width),2);
            max_area = max(max_area,area);
        }

        return max_area;

    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int maximal_Square = 0;
        vector<int> v(matrix[0].size(),0);
    
        for(int i=0; i<matrix.size(); i++){

            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '0') v[j] = 0;
                else v[j] += matrix[i][j]-'0';
            }

            int area = solve(v);
            cout<<area<<" ";
            maximal_Square = max(area,maximal_Square);
        }

        return maximal_Square;
        
    }
};