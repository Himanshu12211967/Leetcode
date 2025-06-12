class Solution {
public:
    bool isPalindrome(int x) {

        int num = x;
        if(num < 0) return false;
        long int second_num = 0;

        while(num != 0){
            int rem = num % 10;
            second_num = second_num * 10 + rem;
            num /= 10;
        }
        
        return second_num == x;
    }
};