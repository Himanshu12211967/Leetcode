class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set<string> st;

        for(int i=0; i<wordList.size(); i++){
            st.insert(wordList[i]);
        }

        if(st.find(endWord) == st.end()) return 0;

        st.erase(beginWord);

        while(!q.empty()){

            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            if(word == endWord) return len;

            for(int i=0; i<word.length(); i++){
                char ori = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word,len+1});
                        st.erase(word);
                    }
                }
                word[i] = ori;
            }

        }

        return 0;
    }
};