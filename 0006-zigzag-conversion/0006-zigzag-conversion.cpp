class Solution {
public:

    string convert(string s, int numRows) {
        
        vector<string> v(numRows);
        int index = 0;
        bool dir = true;

        for(auto ch : s){

            if(index == numRows){
                index-=2;
                dir = false;
            }
            if(index == -1){
                index+=2;
                dir = true;
            }

            if(index >= numRows || numRows <= -1) index = 0;
            v[index].push_back(ch);
            if(dir == true) index++;
            else index--;

        }

        string ans = "";

        for(auto x : v){
            ans += x;
        }

        return ans;

    }
};