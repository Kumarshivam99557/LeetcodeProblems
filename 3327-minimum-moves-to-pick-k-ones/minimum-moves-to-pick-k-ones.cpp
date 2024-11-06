class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int mC) {
        vector<long long> preSum({0});
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]){
                preSum.push_back(preSum.back()+i+1);
            }
        }   
        int m=max(0,k-mC);
        long long ans=1e14;
        n=preSum.size();
        for(int l=m;l<=min(n-1,m+3);l++){
            if(l==0){
                ans=min(ans,(long long)max(0,2*(k-l)));
                continue;
            }
            int mid1=l-l/2;
            int mid2=l/2+1;
            for(int i=0;i<n-l;i++){
                long long res=-(preSum[i+mid1]-preSum[i]) + (preSum[i+l]-preSum[i+mid2-1]);
                res=max(0LL,res);
                ans=min(ans,res+max(0,2*(k-l)));
            }
        }
        return ans;
    }
};