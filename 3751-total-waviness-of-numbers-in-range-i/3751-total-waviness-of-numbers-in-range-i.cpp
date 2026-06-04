class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wave=0;
        for(int i=num1;i<=num2;i++){
            if(!i/100)continue;
            string temp=to_string(i);
            for(int j=1;j<temp.size()-1;j++){
                if(temp[j]>temp[j-1] && temp[j]>temp[j+1] || temp[j]<temp[j-1] && temp[j]<temp[j+1]){
                    wave++;
                }
            }
        }
        return wave;
    }
};