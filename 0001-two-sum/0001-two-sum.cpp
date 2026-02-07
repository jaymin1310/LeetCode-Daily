class Solution {
public:
    vector<int> twoSum(vector<int>& book, int target) {
        int n=book.size();
        vector<int>temp=book;
       sort(book.begin(),book.end());
    int left=0,right=n-1,sum=0;
    while(left<right){
        sum=book[left]+book[right];
        if(sum==target){
            auto it1= find(temp.begin(),temp.end(), book[left]);
            vector<int>:: iterator it2;
            it2=temp.begin();
           while(it2!=temp.end()){
                if((*it2)==book[right] && it2!=it1)break;
                it2++;
           }
            int re=distance(temp.begin(),it1);
            int ree=distance(temp.begin(),it2);
            return {re,ree};
        }
        else if(sum>target)right--;
        else left++;
    }
    return {-1,-1};
    }
};