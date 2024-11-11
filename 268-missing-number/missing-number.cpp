class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            sum= sum+ nums[i];
            ans = ans + i;
        }
        ans = ans + nums.size();
        return ans - sum;
    }
};