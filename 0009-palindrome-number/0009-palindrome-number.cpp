class Solution {
public:

    // 1234 4
    
    bool isPalindrome(int x) {
        
        if(x < 0) return false;

        long long int dup = x;
        long long int number_formed = 0;

        while(dup != 0){
            int rem = dup % 10;
            number_formed = number_formed*10 + rem;
            dup /= 10;
        }

        return (number_formed == x);

    }
};