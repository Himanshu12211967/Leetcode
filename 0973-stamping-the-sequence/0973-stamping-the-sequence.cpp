class Solution {
public:

    bool isPossibleToStamp(string &target,string &stamp,int index){

        int i=0;

        while(i < stamp.length()){
            if(stamp[i] != target[index] && target[index] != '?') return false;
            i++;
            index++;
        }

        return true;
    }

    int replace(string &target,string &stamp,int index){

        int i=0;
        int count = 0;

        while(i < stamp.length()){
            if(target[index] != '?'){
                count++;
                target[index] = '?';
            }
            i++;
            index++;
        }

        return count;
    }

    vector<int> movesToStamp(string stamp, string target) {
        
        vector<int> ans;
        int count = 0;
        vector<bool> visited(target.length(),false);

        while(count != target.length()){

            bool changed = false;

            for(int i=0; i<=target.length()-stamp.length(); i++){

                if(!visited[i] && isPossibleToStamp(target,stamp,i)){
                    visited[i] = true;
                    count += replace(target,stamp,i);
                    ans.push_back(i);
                    changed = true;
                }

            }

            if(changed == false) return {};
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};