class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int x=nums1.size()+nums2.size();
       for(int i=0;i<nums2.size();i++){nums1.push_back(nums2[i]);}
       sort(nums1.begin(),nums1.end());
        if(x%2==1){
        return nums1[(x/2)]/1.00000;
        }
        else return ((nums1[x/2]+nums1[(x/2)-1])/2.00000);
    }
};