class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_size = needle.size();
        int n = haystack.size();
        
        for(int i = 0;i < n; i++){
            if(haystack.substr(i, needle_size) == needle){
                return i;
            }
        }
        return -1;
    }
};
