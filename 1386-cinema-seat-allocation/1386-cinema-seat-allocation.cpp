class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>occupied;
        for(auto &it:reservedSeats){
            occupied[it[0]] |= (1 << it[1]);
        }
        int ans=(n-occupied.size())*2;
        int leftMask  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); 
        int midMask   = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        for(auto &[row,mask]:occupied){
                bool leftFree=(leftMask&mask)==0;
                bool midFree=(midMask&mask)==0;
                bool rightFree=(rightMask&mask)==0;
                if(leftFree & rightFree)ans+=2;
                else if(leftFree||rightFree||midFree)ans+=1;
        }
        return ans;
    }
};