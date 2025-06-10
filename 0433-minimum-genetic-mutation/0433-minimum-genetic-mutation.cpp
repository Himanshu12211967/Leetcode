class Solution {
public:

    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> st;
        char list[] = {'A','C','G','T'};

        for(int i=0; i<bank.size(); i++){
            st.insert(bank[i]);
        }

        queue<pair<int,string>> q;
        q.push({0,startGene});
        int len = INT_MAX;


        while(!q.empty()){

            string word = q.front().second;
            int chainlen = q.front().first;
            q.pop();

            if(word == endGene){
                len = min(len,chainlen);
                continue;
            }

            for(int i=0; i<word.size(); i++){
                char ori = word[i];
                for(char ch : list){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({chainlen+1,word});
                    }
                }
                word[i] = ori;
            }
        }
        
        if(len == INT_MAX) return -1;
        return len;
    }
};