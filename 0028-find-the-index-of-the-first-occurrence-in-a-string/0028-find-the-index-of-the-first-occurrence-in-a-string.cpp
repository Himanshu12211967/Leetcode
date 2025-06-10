class Solution {
public:

    bool exist(string &needle,string &haystack,int i){

        int j=0;

        while(j < needle.size() && i < haystack.size()){
            if(haystack[i] != needle[j]) return false;
            i++;
            j++;
        }

        if(j < needle.size()) return false;
        return true;
    }

    int strStr(string haystack, string needle) {
        
       for(int i=0; i<haystack.size(); i++){
            if(exist(needle,haystack,i)) return i;
       }

       return -1;
    }
};