class Solution {
public:
    int dp[1<<15];
    long long solve(string &target, vector<vector<int>> &sticker_freq, long long mask) {
        int n = target.size();
        if(mask == (1 << n)-1) return 0;
        if(dp[mask] != -1) return dp[mask];
        long long ans = 1e9;
        for(auto freq : sticker_freq) {
            vector<int> temp = freq;
            int new_mask = 0;
            for(int i = 0;i < n;i++) {
                if(mask & (1 << i)) continue;
                if(temp[target[i]-'a'] > 0) {
                    temp[target[i]-'a']--;
                    new_mask |= (1 << i); //taken that particular character
                }
            }
            //check to avoid infinite recursion
            if(new_mask > 0) {
                ans = min(ans, 1 + solve(target,sticker_freq,mask | new_mask));
            }
        }
        return dp[mask] = ans;
    }
    int minStickers(vector<string>& stickers, string target) {
        int sticker_size = stickers.size();
        vector<vector<int>> sticker_freq;
        for(auto &sticker : stickers) {
            vector<int> freq(26,0);
            for(auto &ch : sticker) {
                freq[ch-'a']++;
            }
            sticker_freq.push_back(freq);
        }
        memset(dp,-1,sizeof(dp));
        long long res = solve(target, sticker_freq, 0);
        return (res == 1e9) ? -1 : res;
    }
};