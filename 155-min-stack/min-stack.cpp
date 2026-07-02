class MinStack {
public:
    vector<int> st;
    stack<int> mini;

    MinStack() {}
    void push(int value) {
        st.push_back(value);
        if (mini.empty() || value <= mini.top()) {
            mini.push(value);
        }
    }
    void pop() {
        if (st.back() == mini.top()) {
            mini.pop();
        }
        st.pop_back();
    }
    int top() { return st.back(); }

    int getMin() { return mini.top(); }
};