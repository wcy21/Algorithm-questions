class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans, q(n);
        int head = 0, tail = 0;
        for (int i = 0; i < k - 1; ++i) {
            while (head <= tail && nums[q[tail]] <= nums[i]) tail--;
            q[++tail] = i;
        }
        for (int i = k - 1; i < n; ++i) {
            while (head <= tail && nums[q[tail]] <= nums[i]) tail--;
            q[++tail] = i;
            while (q[head] <= i - k) head++;
            ans.push_back(nums[q[head]]);
        }
        return ans;
    }
};
