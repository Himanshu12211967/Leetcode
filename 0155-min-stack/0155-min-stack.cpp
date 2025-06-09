class MinStack {
public:

    stack<int> st;
    stack<int> minstack;

    MinStack() {
        
    }
    
    void push(int val) {

        st.push(val);

        if(minstack.empty()){
            minstack.push(val);
        }
        else{
            int num = min(minstack.top(),val);
            minstack.push(num);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
        minstack.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minstack.empty()) return -1;
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */