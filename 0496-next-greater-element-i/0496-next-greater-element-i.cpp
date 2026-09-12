class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        stack<int> st;
        vector<int> ans(nums1.size(),0);
        for(int i=nums2.size()-1;i>=0;i--){
             while(!st.empty() && nums2[i]>st.top()){
                st.pop();
             }
             if(st.empty()){
                m[nums2[i]]=-1;
                st.push(nums2[i]);
             }
             else{
                m[nums2[i]]=st.top();
                st.push(nums2[i]);
             }
        }
        for(int i=0;i<nums1.size();i++){
           ans[i]=m[nums1[i]];
        }
    return ans;
    }
};