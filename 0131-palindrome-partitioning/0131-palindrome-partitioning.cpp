class Solution {
public:
    vector<vector<string>>ans;
    bool helper(string temp){
        int start=0;
        int end=temp.size()-1;
        while(start<=end){
            if(temp[start]!=temp[end])return false;
            start++;
            end--;
        }
        return true;
    }
    void recursion(string& s,vector<string>&array,int i,string result){
        if(i>=s.size()){
            ans.push_back(array);
        }
        string temp;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(helper(temp)){
                array.push_back(temp);
                recursion(s,array,j+1,temp);
                array.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        recursion(s,temp,0,"");
        return ans;
    }
};