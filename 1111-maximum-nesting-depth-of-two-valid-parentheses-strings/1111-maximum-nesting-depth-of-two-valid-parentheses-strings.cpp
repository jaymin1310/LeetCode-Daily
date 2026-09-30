class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans(n);
        int brack=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                ans[i]=brack%2;
                brack++;
            }else{
                brack--;
                ans[i]=brack%2;
                
            }
        }
        return ans;
    }
};