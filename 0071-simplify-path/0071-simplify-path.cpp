class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string>st;
        int i=0;

        while(i < path.length()){

            while(i < path.length() && path[i] == '/') i++;

            string word = "";
            while(i < path.length() && path[i] != '/'){
                word += path[i];
                i++;
            }

            if(word == ".." ){
                if(!st.empty())
                st.pop_back();
            }
            else if(word == "." || word == "") continue;
            else st.push_back(word);

        }

        string ans = "";
        if(st.empty()) return "/";

        for(auto s : st){
            ans = ans + '/' + s;
        }
        
        return ans;

    }
};