class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(),digits.end());
        int carry = 1;
        int i=0;

        while(i < digits.size()){

            int num = digits[i];
            num += carry;
            carry = num/10;
            num %= 10;
            digits[i++] = num;
        }

        if(carry != 0) digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;

    }
};