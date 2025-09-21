class Solution {
public:
    vector<vector<int>>ans;
    void recursion(vector<int>&temp,int ind,int k,int n){
        if(k==0){
            if(n==0)ans.push_back(temp);
            return;
        }
        if(n<0)return;
        for(int i=ind;i<=9;i++){
            temp.push_back(i);
            recursion(temp,i+1,k-1,n-i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        recursion(temp,1,k,n);
        return ans;
    }
};