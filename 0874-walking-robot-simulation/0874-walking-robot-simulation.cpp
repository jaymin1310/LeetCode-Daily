class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obst) {
        unordered_set<string>obs;
        for(auto &it:obst){
            string key=to_string(it[0])+","+to_string(it[1]);
            obs.insert(key);
        }
        int x=0,y=1,maxDist=0;
        int xi=0,yi=0;
        for(auto &comm:commands){
            if(comm==-1){
                if(x==0){
                    x=(y==1)?1:-1;
                    y=0;
                }else{
                    y=(x==-1)?1:-1;
                    x=0;
                }
            }else if(comm==-2){
                if(x==0){
                    x=(y!=1)?1:-1;
                    y=0;
                }else{
                    y=(x!=-1)?1:-1;
                    x=0;
                }
            }else{
                for(int i=1;i<=comm;i++){
                    int newxi=xi+x;
                    int newyi=yi+y;
                    string string_key=to_string(newxi)+","+to_string(newyi);
                    if(obs.count(string_key)){
                        break;
                    }
                    xi=newxi;
                    yi=newyi;
                    maxDist = max(maxDist, xi*xi + yi*yi);
                }

            }
        }
        return maxDist;
    }
};