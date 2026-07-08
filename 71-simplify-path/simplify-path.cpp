class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        int i = 1;
        string str = "";
        while (i < path.size()) {
            if (path[i] == '/') {
                if (str == ".") {
                } else if (str == "..") {
                    if (!st.empty())
                        st.pop();
                } else if (!str.empty()) {
                    st.push(str);
                }
                str.clear();
                i++;
                while (i < path.size() && path[i] == '/') {
                    i++;
                }
            } // "/" occur
            else {
                str += path[i];
                i++;
            } // "any element occur"
        }
        string ans = "";
        if (st.empty()) {
            return "/";
        }
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};