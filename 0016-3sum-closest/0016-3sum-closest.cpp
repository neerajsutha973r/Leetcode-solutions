static const bool __boost = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
}();
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void* ptr) {}
void operator delete(void* ptr, unsigned long) {}
void operator delete[](void* ptr) {}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cs=nums[0]+nums[1]+nums[2];
        int mindiff=abs(target-cs);
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1;
            int r=nums.size()-1;
            while(r>l){
                int sum=nums[i]+nums[l]+nums[r];
                int diff=abs(target-sum);
                if(diff<mindiff){
                    mindiff=diff;
                    cs=sum;
                }
                if(sum<target)
                l++;
                else if(sum>target)
                    r--;
                
                else
                   return sum;
                }
            }
        return cs;   
         }
};