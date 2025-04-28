class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(),digits.end());

        int i=0;
        int carry = 1;

        while(i < digits.size()){

            int num = digits[i];
            int sum = num + carry;
            carry = sum/10;
            sum = sum%10;
            digits[i] = sum;
            i++;
        }

        if(carry != 0) digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;

    }
};