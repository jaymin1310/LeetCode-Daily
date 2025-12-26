class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size(),candy=n,i=1;
        while(i<n){
            int top=0,down=0;
            if(arr[i]==arr[i-1]){
                i++;
                continue;
            }
            while(i<n && arr[i]>arr[i-1]){
                top++;
                candy+=top;
                i++;
            }
            while(i<n && arr[i]<arr[i-1]){
                down++;
                candy+=down;
                i++;
            }
            candy-=min(top,down);
        }
        return candy;
    }
};