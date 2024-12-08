class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        int n = s.length();
        vector<vector<int>> count(n+1, vector<int>(26, 0));

        // Storing Frequencies 
        for(int i=1; i<=n; i++) {
            for(int j=0; j<26; j++) {
                count[i][j] += count[i-1][j] + (s[i-1]==('a'+j));
            }
        }

        vector<bool> ans;

        for(auto i: queries) {

            int start = i[0]+1;
            int end = i[1]+1;
            int k = i[2];

            // Strong the Size of string in given Query
            int remaining = (end-start+1);
            int oddCount = 0;

            for(int j=0; j<26; j++) {

                // Relaxing 
                int tp = count[end][j]-count[start-1][j];

                remaining -= (tp - (tp&1));
                oddCount += tp&1;

            }
            // If after relaxing remaning is odd we use any one oddCount to fill the middle element
            if((end-start+1)%2==1 && oddCount>=1) {
                remaining--;
            }
             

            if((remaining+1)/2 <=k ) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }

        }
        return ans;



    }
};