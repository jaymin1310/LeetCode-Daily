class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int pos=1<<n;
        vector<int>arr(pos,0);
        for(auto &it:nums){
            int num=stoi(it,0,2);
            arr[num]=1;
        }
        for(int i=0;i<pos;i++){
            if(!arr[i]){
                string binary = bitset<16>(i).to_string();
                return binary.substr(16-n);
            }
        }
        return "";
    }
};