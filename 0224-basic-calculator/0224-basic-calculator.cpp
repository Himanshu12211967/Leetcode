class Solution {
public:
    int calculate(string s) {
        
        int sum = 0;
        stack<int>st;
        int i=0;
        int sign = 1;

        while(i < s.length()){

            if(s[i] == ' '){
                i++;
                continue;
            }

            else if(s[i] == '+'){
                sign = 1;
            }

            else if(s[i] == '-'){
                sign = -1;
            }

            else if(s[i] == '('){
                st.push(sum);
                st.push(sign);
                sign = 1;
                sum = 0;
            }

            else if(s[i] == ')'){
                sum *= st.top();st.pop();
                sum += st.top();st.pop();
            }

            else{
                int num = 0;
                while(i < s.length() && isdigit(s[i])){
                    num = num*10+(s[i]-'0');
                    i++;
                }

                num *= sign;
                sum += num;
                continue;
            }

            i++;

        }

        return sum;
    }
};