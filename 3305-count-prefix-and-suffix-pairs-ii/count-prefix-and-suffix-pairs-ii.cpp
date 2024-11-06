class Solution {
public:
    
    long long countPrefixSuffixPairs(vector<string>& words) {
        map<string,int> mp;
        int n=words.size();
        long long ans=0;
        for(int i=0 ; i<n  ; i++){
            string s=words[i];
            string w1="";
            string w2="";
            for(int j=0 ; j<words[i].size() ; j++){
                w1+=words[i][j];
                w2+=words[i][words[i].size()-1-j];
                if(mp.count(w1)){
                    string r=w2;
                    reverse(r.begin(),r.end());
                    if(r==w1){
                        ans+=mp[w1];
                    }
                }
            }
            mp[s]++;
        }
        return ans;
    }
};