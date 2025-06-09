class Solution {
public:

    int solve(string &a,string &b,int i,int j){

        if(i == a.length()) return 1;
        if(i < a.length() && j == b.length()) return 0;

        if(a[i] == b[j]){
            return solve(a,b,i+1,j+1);
        }
        else{
            return solve(a,b,i,j+1);
        }

    }

    bool isSubsequence(string s, string t) {
        
        return solve(s,t,0,0);

    }
};