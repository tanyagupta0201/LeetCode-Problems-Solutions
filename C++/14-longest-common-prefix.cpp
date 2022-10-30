class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string t="";
        for(int i=0;i<strs[0].length();i++){
            char x=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i==strs[j].length()){
                    return t;
                }
                if(x!=strs[j][i]){
                    return t;
                }
            }
            t=t+x;
        }
        return t;
    }
};