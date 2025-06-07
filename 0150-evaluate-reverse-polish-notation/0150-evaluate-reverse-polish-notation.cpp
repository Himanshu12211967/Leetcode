class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;

        for(auto str : tokens){

            if(str == "+"){
                int b = st.top();st.pop();
                int a = st.top();st.pop();
                st.push(a+b);
            }
            else if(str == "*"){
                int b = st.top();st.pop();
                int a = st.top();st.pop();
                st.push(a*b);
            }
            else if(str == "-"){
                int b = st.top();st.pop();
                int a = st.top();st.pop();
                st.push(a-b);
            }
            else if(str == "/"){
                int b = st.top();st.pop();
                int a = st.top();st.pop();
                st.push(a/b);
            }
            else{
                st.push(stoi(str));
            }

        }

        return st.top();
    }
};