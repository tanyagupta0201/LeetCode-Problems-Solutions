class Solution {
public:
    bool canJump(vector<int>& nums) {
        int x=nums.size()-1;
        for(int i=x-1;i>=0;i--){
            nums[i]+=i;
            if(nums[i]>=x) x = i;
        }
        return x==0 ? true:false;
    }
};