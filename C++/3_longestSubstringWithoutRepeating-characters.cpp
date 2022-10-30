class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0,cnt;
        int a[130];
        for(int i=0;i<s.length();i++){
            for(int j=0;j<130;j++){
                a[j]=0;
            }
            cnt=0;
            for(int j=i;j<s.length();j++){
                if(a[s[j]]==1){
                    break;
                }
                else{
                    a[s[j]]=1;
                    cnt++;
                }
            }
            if(cnt>max){
                max=cnt;
            }
        }
        return max;
    }
};