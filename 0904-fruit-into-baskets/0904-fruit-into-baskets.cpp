class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()==1) return 1;
        else if(fruits.size()==2) return 2;
        int maxf=-1;
        unordered_map<int,int>m;
        int l=0;
        for(int r=0;r<fruits.size();r++){
            m[fruits[r]]++;
            while(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0) m.erase(fruits[l]);
                l++;
            }
            maxf=max(maxf,r-l+1);
        }
        return maxf;
    }
};