class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty())
                    break;

                int w = i - stk.top() - 1;
                int h = min(height[i], height[stk.top()]) - height[top];
                ans += w * h;
            }

            stk.push(i);
        }
        return ans;
    }
};
