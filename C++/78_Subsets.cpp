// Name: Shradha Verma
// Date: 13-10-2022

class Solution {
public:
    void solve(vector<int>nums, vector<int>op, vector<vector<int>>&res){

        if(nums.size() == 0){
            res.push_back(op);
            return;
        }

        vector<int>op1;
        vector<int>op2;
        
        op1 = op;
        op2 = op;
        op2.push_back(nums[0]);
        nums.erase(nums.begin()+ 0);
        
        solve(nums, op1, res);
        solve(nums, op2, res);
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int>op;
        vector<vector<int>>res;
        solve(nums, op, res);

        return res;
    }
};