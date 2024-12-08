class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        set<string> hash;
        for(int i=0;i<=s.size() - k;i++) {
            hash.insert(s.substr(i,k));
        }
        long long res = 1;
        while(k--) res *= 2;
        return res == hash.size();
    }
};