class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans;
        for(int i=0;i<n1;i++){
            int flag=0;
            int res=-1;
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j])flag=1;
                if(nums2[j]>nums1[i] && flag==1){
                    res=nums2[j];
                    break;
                }
            }
            ans.push_back(res);

        }
        return ans;
    }
};