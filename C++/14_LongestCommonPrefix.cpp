//Name: Akashdeep Singh Kataria
//Date: 15/10/2022

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int common = 200;
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(j<strs[i].length() && strs[i][j]==strs[0][j])
                j++;
            common = min(common, j);
        }
        return strs[0].substr(0, common);
    }
};