class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        int n=ast.size();
        sort(ast.begin(),ast.end());
        long long currMass=mass;
        for(int i=0;i<n;i++){
            if(ast[i]>currMass)return false;
            currMass+=(long long)ast[i];
        }
        return true;
    }
};