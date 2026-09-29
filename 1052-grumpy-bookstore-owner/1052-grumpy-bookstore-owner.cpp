class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxsum=0;
        int grusum=0;
        int sum=0;
        int a=0;
        int l=0;
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        for(int r=0;r<customers.size();r++){
            if(grumpy[r]==1) grusum+=customers[r];
            if(r-l+1>minutes){
                if(grumpy[l]==1){
                grusum-=customers[l];
                }
                l++;
            }
            maxsum=max(maxsum,grusum);
        }
        return sum+maxsum;
    }
        
};