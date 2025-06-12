class Solution {
public:

    bool solve(string s,unordered_set<string> &wordDict,map<string,bool> &dp){

        if(s.empty()) return true;
        if(dp.find(s) != dp.end()) return dp[s];

        for(int i=1; i<=s.length(); i++){
            string sub = s.substr(0,i);
            string rem = s.substr(i);
            if(wordDict.find(sub) != wordDict.end()){
                if(solve(rem,wordDict,dp)) return dp[sub] = true;
            }
        }

        return dp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> m;
        map<string,bool> dp;
        for(int i=0; i<wordDict.size(); i++){
            m.insert(wordDict[i]);
        }
        return solve(s,m,dp);
    }
};