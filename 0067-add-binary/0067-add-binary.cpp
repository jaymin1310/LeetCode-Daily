class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int alen=a.length()-1;
        int blen=b.length()-1;
        int carry=0;
        while(alen>=0 && blen>=0){
            char temp='0';
            if(a[alen]=='1' && b[blen]=='1'){
                if(carry){
                    temp='1';
                }else{
                    carry=1;
                }
            }else if(a[alen]=='1' || b[blen]=='1'){
                if(!carry){
                    temp='1';
                }
            }else{
                if(carry){
                    temp='1';
                    carry=0;
                }
            }
            ans.insert(ans.begin(),temp);
            alen--;
            blen--;
        }
        while(alen>=0){
            char temp='0';
            if(a[alen]=='1'){
                if(!carry)temp='1';
            }else{
                if(carry){
                    temp='1';
                    carry=0;
                }
            }
            ans.insert(ans.begin(),temp);
            alen--;
        }
        while(blen>=0){
            char temp='0';
            if(b[blen]=='1'){
                if(!carry)temp='1';
            }else{
                if(carry){
                    temp='1';
                    carry=0;
                }
            }
            ans.insert(ans.begin(),temp);
            blen--;
        }
        if(carry)ans.insert(ans.begin(),'1');
        return ans;
    }
};