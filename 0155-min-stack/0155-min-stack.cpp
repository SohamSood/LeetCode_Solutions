class MinStack {
public:
    stack<int> st;
    stack<int> minstack;
    MinStack() {
        
    }
    
    void push(int value) {
        if(minstack.empty() || minstack.top() >= value) {
            minstack.push(value);
        }
        st.push(value);
    }
    
    void pop() {
        if(!st.empty()) {
            if(st.top() == minstack.top()) {
                minstack.pop();
            }
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()) return st.top();
        return -1;
    }
    
    int getMin() {
        if(!st.empty()) return minstack.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */