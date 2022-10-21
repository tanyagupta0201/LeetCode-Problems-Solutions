// Name: Shreya Shankar
// Date: 21/10/2022

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    int size = candidates.size();
    if (size == 0) return result;
    sort(candidates.begin(), candidates.end());
    vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
    dp[0].push_back(vector<int>());
    
    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < size && candidates[j] <= i; ++j) {
            for (int k = 0; k < dp[i - candidates[j]].size(); ++k) {
                vector<int> temp = dp[i - candidates[j]][k];
                if (temp.size() && (temp[temp.size() - 1] > candidates[j])) continue;
                temp.push_back(candidates[j]);
                dp[i].push_back(temp);
            }
        }
    }
    return dp[target];
}
