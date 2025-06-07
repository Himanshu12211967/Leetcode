class Solution {
public:

    void solve(string &digits,int idx,vector<string> &ans,string temp,vector<string> &keypad){

        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }

        string word = keypad[digits[idx]-'0'];

        for(int i=0; i<word.length(); i++){
            solve(digits,idx+1,ans,temp+word[i],keypad);
        }

    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};
        vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string> ans;
        solve(digits,0,ans,"",keypad);
        return ans;

    }
};