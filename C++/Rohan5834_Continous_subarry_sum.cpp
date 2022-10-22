class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]%k==0&&nums[i-1]%k==0)
                return true;
            if(nums[i]%k==0)
                continue;
            sum+=nums[i];
            int u=sum%k;
            cout<<u<<" ";
            if(u==0)
                return true;
            if(m.find(u)!=m.end()&&m[u]!=i)
                return true;
            m[u]=i;
            
        }
        return false;   
    }
};
