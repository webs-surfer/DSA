class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> answer(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            if (st.empty()) {
                answer[i] = 0;
                st.push(i);
            } else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    answer[st.top()] = i - st.top();
                    st.pop();
                }
                if (st.empty()) {
                    answer[i] = 0;
                    st.push(i);
                }else{
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            answer[st.top()]=0;
            st.pop();
        }
        return answer;
    }
};