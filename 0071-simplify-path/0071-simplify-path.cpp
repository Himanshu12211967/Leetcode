class Solution {
public:

    string simplifyPath(string path) {
        
        vector<string> stack;
        int i=0;

        while(i < path.size()){

            while(i < path.size() && path[i] == '/') i++;

            string dir = "";
            while(i < path.size() && path[i] != '/'){
                dir += path[i];
                i++;
            }

            if(dir == "" || dir == ".") continue;
            else if(dir == ".."){
                if(!stack.empty()) stack.pop_back();
            }
            else stack.push_back(dir);
        }

        string result = "";
        if(stack.empty()) return "/";

        for(auto s : stack){
            result = result + "/" + s;
        }

        return result;

    }
};