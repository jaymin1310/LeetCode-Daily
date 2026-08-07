class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n=arr.size();
        int one=0;
        for(int i=0;i<n;i++){
            if(arr[i])one++;
        }
        int wrong=0;
        for(int i=0;i<one;i++){
            if(!arr[i])wrong++;
        }
        int ans=wrong;
        int j;
        for(j=one;j<n;j++){
            if(!arr[j])wrong++;
            if(!arr[j-one])wrong--;
            ans=min(wrong,ans);
        }
        int l=n-one;
        while(l%n){
            if(!arr[j%n])wrong++;
            if(!arr[l])wrong--;
            l++;
            j++;
            ans=min(wrong,ans);
        }
        return ans;
    }
};