class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int i = nums2.size() - 1;
        unordered_map<int, int> mp;
        while (i >= 0) {
            if (!st.empty()) {
                if (nums2[i] < st.top()) {
                    mp[nums2[i]] = st.top();
                    st.push(nums2[i]);
                } else {
                    while (!st.empty() && nums2[i] >= st.top()) {
                        st.pop();
                    }
                    if (st.empty()) {
                        mp[nums2[i]] = -1;
                        st.push(nums2[i]);
                    } else {
                        mp[nums2[i]] = st.top();
                        st.push(nums2[i]);
                    }
                }
            } else {
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            i--;
        }
        for(int i=0; i<nums1.size(); i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};