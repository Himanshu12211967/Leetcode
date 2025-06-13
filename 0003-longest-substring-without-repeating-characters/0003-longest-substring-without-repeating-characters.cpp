class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = 0;
        int len = 0;
        vector<bool> visited(256,false);

        while(right < s.length()){

            if(!visited[s[right]]){
                visited[s[right]] = true;
                len = max(len,right-left+1);
                right++;
            }
            else{
                visited[s[left]] = false;
                left++;
            }

        }

        return len;
    }
};