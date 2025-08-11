class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(n!=goal.size())return false;
        string temp=s;
        temp+=s;
        if(temp.find(goal)!=string::npos){
            return true;
        }
        return false;
    }
};