class Solution {
public:

    void solve(int rem, string &str){

        if(rem < 10){
            str = char('0' + rem) + str;
        }
        else{
            str = char('a' + (rem-10)) + str;
        }

    }

    string toHex(int num) {
        
        if(num == 0) return "0";
        unsigned int n = static_cast<unsigned int>(num); 
        string str = "";

        while(n > 0){

            int rem = n % 16;
            solve(rem,str);
            n /= 16;
        }

        return str;
    }
};