class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int k=2;k<n;k++){
            int i=0,j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    cnt+=j-i;
                    j--;
                }
                else i++;
            }
        }
        return cnt;
    }
};