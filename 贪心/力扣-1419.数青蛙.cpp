class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0)
            return -1;
        
        int n = croakOfFrogs.size(), ans = 0, num = 0, cnt[4] = {0};
        map<char, int> mp = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        for (int i = 0; i < n; ++i) {
            int t = mp[croakOfFrogs[i]];
            if (t == 0) {
                cnt[t]++;
                num++;
                if (num > ans)
                    ans = num;
            }
            else {
                if (cnt[t - 1] == 0)
                    return -1;
                cnt[t - 1]--;
                if (t == 4)
                    num--;
                else
                    cnt[t]++;
            }
        }
        if (num > 0)
            return -1;
        return ans;
    }
};
