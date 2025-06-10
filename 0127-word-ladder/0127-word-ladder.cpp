class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int len = INT_MAX;
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        set<string> m;

        for(int i=0; i<wordList.size(); i++){
            m.insert(wordList[i]);
        }

        m.erase(beginWord);

        while(!q.empty()){

            string word = q.front().first;
            int chainlen = q.front().second;
            q.pop();

            if(word == endWord){
                len = min(len,chainlen);
            }

            for(int i=0; i<word.length(); i++){
                char ori = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(m.find(word) != m.end()){
                        q.push({word,chainlen+1});
                        m.erase(word);
                    }
                }
                word[i] = ori;
            }
        }

        if(len == INT_MAX) return 0;
        return len;
    }
};