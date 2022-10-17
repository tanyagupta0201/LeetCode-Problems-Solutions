// Name : A VINAY KUMAR
// Date : 06/10/2022

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // base case
        if(nums.size() <= 1) {
            return {nums};
        }

        //vector to store the permutations
        vector<vector<int>> ans;
        for(auto it = nums.begin();it != nums.end();it++) {
            vector<int> temp(nums.begin(), nums.end());

            //removing the current item and receiving all the permutations of rest
            temp.erase(find(temp.begin(),temp.end(),*it));
            vector<vector<int>> tempans  = permute(temp);
            for(auto x: tempans) {

                // adding the removed item to all the permutations received
                x.insert(x.begin(), *it);
                ans.push_back(x);
            }
         }
        return ans;
    }
};