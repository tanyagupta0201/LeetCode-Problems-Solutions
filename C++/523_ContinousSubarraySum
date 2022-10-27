class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sum=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum%k==0 && i!=0)
                return true;
            if(m.find(sum%k)==m.end())
                m[sum%k]=i;
            else if(i-m[sum%k] > 1)
                return true;
        }
        return false;
    }
};