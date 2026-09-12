class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;
        for(int i=2*nums.size()-1;i>=0;i--){
            int idx=i%nums.size();
            while(!st.empty() && st.top()<=nums[idx]) st.pop();
            if(st.empty()){
                ans[idx]=-1;
                st.push(nums[idx]);
            }
            else{
                ans[idx]=st.top();
                st.push(nums[idx]);
            }
        }
        return ans;
    }
};