class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(),digits.end());
        int carry = 1;

        for(int i=0; i<digits.size(); i++){
            int sum = carry + digits[i];
            carry = sum/10;
            sum %= 10;
            digits[i] = sum;
        }

        if(carry) digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};