class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        double ans;
        if((m+n)%2==0){
            int ind1=(m+n)/2;
            int ind2=ind1-1;
            if(ind1<n){
                ans=(double)(nums1[ind1]+nums1[ind2])/2.0;
            }
            else if(ind1>=n && ind2<n){
                ans= (double)(nums2[ind1-n]+nums1[ind2])/2.0;
            }
            else{
                ans= (double)(nums2[ind1-n]+nums2[ind2-n])/2.0;
            }
        }
        else{
            int ind=(m+n)/2;
            if(ind<n)ans=nums1[ind];
            else ans=nums2[ind-n];
        }
        return ans;
    }
};