class Solution {
public:
    map<vector<int>,int> hash;
    void solve(int indx, vector<int> &ans, vector<vector<int>> &result , int sum , vector<int>& candidates, int target){
        if(indx>=candidates.size() or sum>=target){
            if(sum==target and hash.count(ans)==0){
                hash[ans]++;
                result.push_back(ans);
            }
            return;
        }
        
        sum+=candidates[indx];
        ans.push_back(candidates[indx]);
        solve(indx+1,ans,result,sum,candidates,target);
        solve(indx,ans,result,sum,candidates,target);
        sum-=candidates[indx];
        ans.pop_back();
        solve(indx+1,ans,result,sum,candidates,target);
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<int> ans;
        vector<vector<int>> result;
        solve(0,ans,result,sum,candidates,target);
        
        return result;
    }
};