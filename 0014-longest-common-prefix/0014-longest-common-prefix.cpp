class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        
        string lcp = "";
        string word = strs[0]; // flower

        for(int i=0; i<word.length(); i++){

            for(int j=1; j<strs.size(); j++){

                string word2 = strs[j];

                if(word2.length() <= i || word[i] != word2[i]) return lcp;
        
            }

            lcp.push_back(word[i]);

        }

        return lcp;

    }
};