class Solution {
public:

    int lengthOfLastWord(string s) {
        
        int i=s.length()-1;
        while(i >= 0 && s[i] == ' ') i--;
        int len = 0;

        for(int j=i; j>=0 && s[j] != ' '; j--){
            len++;
        }

        return len;
    }
};