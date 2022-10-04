class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int t_sum=0,f_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                t_sum++;
                if(t_sum>=f_sum)
                    f_sum=t_sum;
            }
            else{
                t_sum=0;
            }
        }
        return f_sum;
    }
};
