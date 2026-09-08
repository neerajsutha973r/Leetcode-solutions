class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ml=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            while(m[nums[i]]>k){
                m[nums[l++]]--;
            }
            ml=max(ml,i-l+1);
        }
        return ml;
    }
};