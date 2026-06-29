class Solution {
public:
    int findDays(vector<int>& weights, int mid) {
        int cnt = 0;
        int i = 0;
        int temp = mid;
        while (i < weights.size()) {
            if (temp - weights[i] < 0) {
                cnt++;
                temp = mid;
            }
            temp -= weights[i];
            i++;
        }
        return cnt + 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int e = accumulate(weights.begin(), weights.end(), 0);
        int s = *max_element(weights.begin(), weights.end());
        int mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            int total = findDays(weights, mid);
            if (total <= days && mid >= s) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};