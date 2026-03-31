class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string ans(n + m - 1, 'X');
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = i; j < i + m; j++) {
                    if (ans[j] == 'X') {
                        ans[j] = str2[j - i];
                    } else {
                        if (ans[j] != str2[j - i])
                            return "";
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool isMatch = true;
                for (int j = i; j < i + m; j++) {
                    if (ans[j] != 'X' && ans[j] != str2[j - i]) {
                        isMatch = false;
                        break;
                    }
                }
                int lastInd=-1;
                if (isMatch) {
                    for (int j = i; j < i + m; j++) {
                        if (ans[j] =='X' && str2[j-i]!='a'){
                            isMatch=false;
                            break;
                        }else if(ans[j]=='X'){
                            lastInd=j;
                        }
                    }
                }
                if(isMatch && lastInd!=-1){
                    ans[lastInd]='b';
                    isMatch=false;
                }
                if(isMatch)return "";
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 'X')
                ans[i] = 'a';
        }
        return ans;
    }
};