class Solution {
public:
    
        double myPow(double x, int n) {
    double ans = 1.0;
    long long N = n; 

    if (N < 0) {
        N = -N;
        x = 1.0 / x;
    }

    while (N > 0) {
        if(N%2==1){
            ans *= x;
        }
        x *= x; 
        N /= 2; 
    }
    return ans;
}
    };