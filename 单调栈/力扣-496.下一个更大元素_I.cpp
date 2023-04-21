class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> stk;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!stk.empty() && stk.top() <= num)
                stk.pop();
            mp[num] = stk.empty() ? -1 : stk.top();
            stk.push(num);
        }
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};
