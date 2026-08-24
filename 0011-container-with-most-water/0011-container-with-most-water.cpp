class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int ma=0;
        while(left<right){
          int ch=min(height[left],height[right]);
          int cw=right-left;
          ma=max(ma,ch*cw);
          if(height[left]<height[right]) left++;
          else right--;
        }
        return ma;
    }
};