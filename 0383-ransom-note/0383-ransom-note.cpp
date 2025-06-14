class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> count(26,0);

        for(int i=0; i<magazine.length(); i++){
            count[magazine[i]-'a']++;
        }

        for(int i=0; i<ransomNote.length(); i++){
            count[ransomNote[i]-'a']--;
            if(count[ransomNote[i]-'a'] < 0) return false;
        }

        return true;
    }
};