class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        vector<int>freq(256,0);
        for(int i=0;i<n;i++){
            freq[(unsigned char)(s[i])]++;
        }
       vector<pair<char,int>>temp;
       for(int i=0;i<256;i++){
        if(freq[i]>0){
            temp.push_back({char(i),freq[i]});
        }
       }
       sort(temp.begin(),temp.end(),[](auto &a,auto &b){
        return a.second>b.second;
       });
       string tem;
       for(auto it:temp){
        tem.append(it.second,it.first);
       }
       return tem;

    }
};