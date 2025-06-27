class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int num = start ^ goal;
        int count = 0;
        
        while(num){
            num &= (num-1);
            count++;
        }

        return count;

    }
};