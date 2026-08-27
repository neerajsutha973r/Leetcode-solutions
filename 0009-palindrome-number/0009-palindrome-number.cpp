class Solution {
public:
    bool isPalindrome(int x) {
        double r=0;
        int a=x;
        while(a>0){
           r=(r*10)+(a%10);
             a=a/10;
           }
           return r==x?1:0;
    }
};