class Solution {
public:
    bool possible(vector<int>& nums, int k, int mid) {
        int subarrays = 1;
        int sum = 0;

        for (int num : nums) {
            if (sum + num <= mid) {
                sum += num;
            } else {
                subarrays++;
                sum = num;
            }
        }
        return subarrays <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int mid;
        int ans = e;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (possible(nums, k, mid)) {
                ans = min(mid, ans);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};