class Solution {
public:

    string intToRoman(int num) {
        
        string roman = "";

        int rem = num % 10;
        num /= 10;

        if(rem == 4) roman += "VI";
        else if(rem == 9) roman += "XI";
        else if(rem <= 3) {
            for(int i=1; i<=rem; i++) roman.push_back('I');
        }
        else{
            rem -= 5;
            for(int i=1; i<=rem; i++) roman.push_back('I');
            roman.push_back('V'); 
        }

        if(num == 0){
            reverse(roman.begin(),roman.end());
            return roman;
        }
        rem = num % 10;
        num /= 10;

        if(rem == 4) roman += "LX";
        else if(rem == 9) roman += "CX";
        else if(rem <= 3) {
            for(int i=1; i<=rem; i++) roman.push_back('X');
        }
        else{
            rem -= 5;
            for(int i=1; i<=rem; i++) roman.push_back('X');
            roman.push_back('L'); 
        }

        if(num == 0){
            reverse(roman.begin(),roman.end());
            return roman;
        }
        rem = num % 10;
        num /= 10;

        if(rem == 4) roman += "DC";
        else if(rem == 9) roman += "MC";
        else if(rem <= 3) {
            for(int i=1; i<=rem; i++) roman.push_back('C');
        }
        else{
            rem -= 5;
            for(int i=1; i<=rem; i++) roman.push_back('C');
            roman.push_back('D'); 
        }

        if(num == 0){
            reverse(roman.begin(),roman.end());
            return roman;
        }
        rem = num % 10;
        num /= 10;

        for(int i=1; i<=rem; i++) roman.push_back('M');

        reverse(roman.begin(),roman.end());
        return roman;

    }
};