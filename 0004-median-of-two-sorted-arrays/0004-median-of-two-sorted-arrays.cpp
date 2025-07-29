class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n2<n1)return findMedianSortedArrays(nums2,nums1);
        int low=0,high=n1;
        int leftTot=(n1+n2+1)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int mid1=mid;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            int mid2=leftTot-mid;
            if(mid1>0)l1=nums1[mid1-1];
            if(mid2>0)l2=nums2[mid2-1];
            if(mid1<n1)r1=nums1[mid1];
            if(mid2<n2)r2=nums2[mid2];
            int leftmax=max(l1,l2);
            int rightmin=min(r1,r2);
            if(leftmax<=rightmin){
                if((n1+n2)%2==0){
                    return (leftmax + rightmin) / 2.0;

                }
                else{
                    return leftmax;
                }
            }
            else if(l1>r2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return 0;
    }
};