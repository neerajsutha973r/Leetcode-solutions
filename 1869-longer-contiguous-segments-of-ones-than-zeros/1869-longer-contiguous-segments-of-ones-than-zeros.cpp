class Solution {
public:
    bool checkZeroOnes(string s) {
        int c0=0;
        int c1=0;
        int max0=0;
        int max1=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                c1++;
                max1=max1>c1?max1:c1;
            }
            else{
                c1=0;
            }
            }
            for(int j=0;j<s.length();j++){
            if(s[j]=='0'){
                c0++;
                max0=max0>c0?max0:c0;
            }
            else{
                c0=0;
            }
            }
            if(max1>max0)
                return true;
        
            return false;
    }
};