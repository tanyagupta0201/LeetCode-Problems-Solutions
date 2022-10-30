class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,int> z;
        int k=1;
        for(int i=0;i<n;i++){
            string e = strs[i];
            sort(e.begin(),e.end());
            if(z[e]==0) {
                z[e]=k;
                k++;
            }
        }
        vector<vector<string>> ans(z.size(),vector<string>());
        for(int i=0;i<n;i++){
            string e = strs[i];
            sort(e.begin(),e.end());
            ans[z[e]-1].push_back(strs[i]);
        }
        return ans;
    }
};