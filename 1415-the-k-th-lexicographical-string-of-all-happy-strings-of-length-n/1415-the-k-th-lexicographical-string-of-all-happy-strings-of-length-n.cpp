class Solution {
public:
    string getHappyString(int n, int k) {

        int total = 3 * (1 << (n-1));
        if(k > total) return "";

        string ans = "";
        char last = '#';

        for(int i=0;i<n;i++){
            for(char c : {'a','b','c'}){

                if(c == last) continue;

                int rem = n - i - 1;
                int count = 1 << rem;

                if(k > count){
                    k -= count;
                }
                else{
                    ans += c;
                    last = c;
                    break;
                }
            }
        }

        return ans;
    }
};