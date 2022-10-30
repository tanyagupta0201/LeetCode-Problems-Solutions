class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool a= false;
        while(s[i]==' '){
            i++;
            if(i==s.length()){
                return 0;
            }
        }
        if(s[i]=='-'){
            a=true;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        int y=0;
        while(s[i]>='0' && s[i]<='9'){
            if(y>INT_MAX/10){
                y=INT_MAX;
                if(a){
                    y=INT_MIN;
                }
                break;
            }
            if(y==214748364 && s[i]>'7'){
                y=INT_MAX;
                if(a){
                    y=INT_MIN;
                }
                break;
            }
            y=y*10+int(s[i]-'0');
            i++;
            if(i==s.length()){
                break;
            }
        }
        if(a && y>0){
            y=0-y;
        }
        return y;

    }
};