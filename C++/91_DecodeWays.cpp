// Nmae: Tanisha Garg
// Date: 11/10/2002

class Solution {
public:
    int dp[101];
    int decoding(string s,int i) {
        if(i==s.length()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long int c=0;
        if(s[i]!='0'){
            c+=decoding(s,i+1);
        }
        if(i<s.length()-1 && s[i]!='0' && ((s[i]-'0')*10+s[i+1]-'0')<=26){
            c+=decoding(s,i+2);
        }
        return dp[i]=c;
            
    }
    int numDecodings(string s){
        memset(dp,-1,sizeof(dp));
        return decoding(s,0);
    }
};
