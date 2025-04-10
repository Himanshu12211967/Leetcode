class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        vector<string> ans(numRows);
        bool top_down_dir = true;
        int i=0;

        for(auto ch : s){

            ans[i].push_back(ch);

            if(i == 0) top_down_dir = true;
            if(i == numRows-1) top_down_dir = false;

            if(top_down_dir == false){
                i--;
            }
            else{
                i++;
            }
        }

        string str = "";

        for(auto x : ans){
            str += x;
        }

        return str;

    }
};